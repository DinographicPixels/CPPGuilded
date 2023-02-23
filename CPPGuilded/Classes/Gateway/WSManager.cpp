//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "WSManager.hpp"
#include "static.hpp"

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <future>

#include <thread>

#include <chrono>
#include <exception>

#include <iostream>

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>

#include <boost/asio/ssl.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/websocket/stream.hpp>

#include "Classes/Threadpool.hpp"

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace ssl = net::ssl;
namespace websocket = beast::websocket;
using tcp = net::ip::tcp;

#include "Classes/Exceptions.hpp"

CPPGuilded::WSManager::WSManager(const std::string& token, const std::shared_ptr<Threadpool>& threadpool): threadpool(threadpool), ctx{ssl::context::tlsv13_client}, ioc() {
	this->log = Utils::Logger("CPPGuilded | WSManager");
	this->token = token;
	this->connected = false;
	this->heartbeat_interval = 0;
	this->keepAlive = true;
	this->clientReady = false;
	this->reconnectTimeout = 0;
	this->lastMessageID = "UNDEFINED";
	ctx.set_verify_mode(ssl::verify_peer | boost::asio::ssl::verify_fail_if_no_peer_cert);
	load_ssl_certificates(ctx);
}

CPPGuilded::WSManager::~WSManager() {
	keepAlive = false;
	heartbeat_thread.join();
}

void CPPGuilded::WSManager::startHeartbeating() {
	static unsigned int heartbeatIndex = 0;
	unsigned int taskID = heartbeatIndex++;
	heartbeat_thread = std::thread([this, taskID] {
		log.register_thread(std::this_thread::get_id(), "Thread-Heartbeat-" + std::to_string(taskID));
		while (heartbeat_interval == 0) {
			log.debug("waiting heartbeat interval change");
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		};
		std::cout << "keepalive: " << (keepAlive ? "true": "false") << std::endl;
		lastHeartbeatAck = time(0);
		while(keepAlive){
			if (connected && clientReady){
				if (lastHeartbeatAck * 1000 + heartbeat_interval * 2 < time(0) * 1000){
					std::cout << "Websocket isn't responding, closing.." << std::endl;
					try {
						log.error("Server is not responding. WS closed.");
						ws->close(websocket::close_reason(websocket::close_code::going_away, "Server is not responding"));
					} catch (std::exception& e) {
						log.error("Cannot close websocket.");
						std::cout << "Cannot close websocket." << std::endl;
					}
				}else {
					json payload = this->get_heartbeat_payload();
					try {
						this->send(payload).get();
						log.debug("Heartbeat has been sent.");
					} catch (const std::exception& e) {
						log.error("Cannot send heartbeat message: " + std::string(e.what()));
					}
				}
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(heartbeat_interval));
		}
	});
}

shared_future<void> CPPGuilded::WSManager::TEST(){
	auto connect_future = threadpool->execute([this] {
		std::cout << "HAAAAAAAAAAAAAAAAAAAAAA" << std::endl;
	});
	return threadpool->then(connect_future, [this] {
		threadpool->execute([this] {
			std::cout << "then it's done" << std::endl;
		});
	});
}

shared_future<void> CPPGuilded::WSManager::connect() {
	std::cout << "connection started" << std::endl;
	string url = "wss://guilded.com/websocket/v1";
	auto connect_future = threadpool->execute([this, url]() {
		tcp::resolver resolver{ioc};
		auto results = resolver.resolve(GUILDED_HOST, "443");
		ws = std::make_unique<websocket::stream<beast::ssl_stream<tcp::socket>>>(ioc, ctx);
		auto endpoint = net::connect(get_lowest_layer(*ws), results);
		if (!SSL_set_tlsext_host_name(ws->next_layer().native_handle(), GUILDED_HOST)) {
			throw beast::system_error(beast::error_code(static_cast<int>(::ERR_get_error()), net::error::get_ssl_category()),
				"Failed to set SNI Hostname");
		}
		ws->set_option(websocket::stream_base::decorator(
			[](websocket::request_type& req){
				req.set(http::field::user_agent, "TEST USERAGENT");
				req.set(http::field::sec_websocket_protocol, "HTTPS");
				req.set(http::field::authorization, "Bearer gapi_jQlwqi1jzqrm6eTeWdQZ+rHrqwofVNlFGIFeCBSxLeuHGVVFOQsRSH4pm8iGIYokw3wAt6A/lbVsUDH4EjZipg==");
			}));

		ws->next_layer().handshake(ssl::stream_base::client);
		ws->handshake(GUILDED_HOST + std::string(":") + std::to_string(endpoint.port()), "/websocket/v" + to_string(GUILDED_APIVERSION));

		if (heartbeat_thread.get_id() == std::thread::id()){
			startHeartbeating();
		}

		connected = true;
		std::cout << "Successfully connected to Guilded." << std::endl;
		log.info("Successfully connected to endpoint: " + endpoint.address().to_string() + ":" + std::to_string(endpoint.port()));
		sleep(2);
	});
	return threadpool->then(connect_future, [this](){
		threadpool->execute([this](){
			log.debug("starting message, reviving loop.");
 			while (connected){
				log.info("is connected.");
				beast::flat_buffer buffer;
				beast::error_code errCode;
				size_t bytes = ws->read(buffer, errCode);

				if (errCode == boost::beast::errc::operation_canceled || errCode == boost::asio::ssl::error::stream_truncated || bytes <= 0) {
					log.warning("disconnected");
					on_websocket_disconnect();
					break;
				}

				if (errCode) {
					std::cout << "err message: " << errCode.message() << std::endl;
					continue;
				}

				std::stringstream message_stream;
				message_stream << beast::make_printable(buffer.data());
				std::string message = message_stream.str();

				try {
					log.debug("sending payload...");
					on_websocket_message(message);
				} catch (const std::exception& e) {
					std::cout << "Error while handling incoming message: " + std::string(e.what());
				}
			}
		});
	});
}

bool CPPGuilded::WSManager::getState() {
	if (ws->is_open()) return true; else return false;
}
void CPPGuilded::WSManager::on_websocket_message(const string& message) {
	json payload = json::parse(message);
	std::cout << "websocket message" << std::endl;
	std::cout << payload.dump(4, ' ') << std::endl;
	// log.debug(payload);
	if (payload.count("s") > 0) lastMessageID = payload["s"].get<std::string>();
	int payloadOPCode = payload.count("op") > 0 ? payload["op"].get<int>() : throw "OP Code not provided by API.";
	const int GatewayOPCode_Event = 0;
	const int GatewayOPCode_Welcome = 1;
	const int GatewayOPCode_Resume = 2;

	threadpool->execute([this, payload, payloadOPCode]{
		switch(payloadOPCode){
			case GatewayOPCode_Event: {
				std::string payloadEventName = payload.count("t") > 0 ? payload["t"].get<std::string>() : throw "Couldn't get payload event name.";
				json payloadData = payload.count("d") > 0 ? payload["d"].get<json>() : throw "Couldn't get payload data.";
				this->ON_GATEWAY_PARSED_PACKET(payloadEventName, payloadData);
				break;
			}
			case GatewayOPCode_Welcome: {
				json payloadData = payload.count("d") > 0 ? payload["d"].get<json>() : throw "Couldn't get payload data.";
				if (payloadData.count("heartbeatIntervalMs") > 0) heartbeat_interval = payloadData["heartbeatIntervalMs"].get<int>();
				std::cout << "heartbeat interval: " << heartbeat_interval << std::endl;
				clientReady = true;
				break;
			}
			case GatewayOPCode_Resume: {

				break;
			}
			default: {
				break;
			}
		};
	});
}

void CPPGuilded::WSManager::on_websocket_disconnect() {
	log.info("Websocket connection closed");
	connected = false;
	clientReady = false;
	if (keepAlive == false) { return; };

	threadpool->execute([this] {
		log.info("trying to reconnect in " + std::to_string((double)reconnectTimeout / 1000) + "s");
		std::this_thread::sleep_for(std::chrono::milliseconds(reconnectTimeout));

		if (reconnectTimeout == 0) {
			reconnectTimeout = 1000;
		} else if (reconnectTimeout < 90000) {  // cap timeout to about 15 min
			reconnectTimeout = (unsigned int)(reconnectTimeout * 1.5);
		}

		try {
			connect().get();
			log.info("reconnected");
			reconnectTimeout = 0;
		} catch (const beast::system_error& e) {
			log.error("Failed to reconnect: " + std::string(e.what()));
			on_websocket_disconnect();
		}
	});
}

std::shared_future<void> CPPGuilded::WSManager::close() {
	keepAlive = false;
	connected = false;
	clientReady = false;
	return threadpool->execute([this]() {
		try {
			get_lowest_layer(*ws).close();
		} catch (const std::exception& e) {
			log.error("Error while closing websocket: " + std::string(e.what()));
		}
	});
}

std::shared_future<void> CPPGuilded::WSManager::send(const json& message) {
	return threadpool->execute([this, message]() {
		if (connected == false) {
			throw ClientException("Gateway not connected");
		}
		// std::string message_string = message.dump();
		// log.debug("sending message: " + message_string);
		beast::error_code error_code;
		ws->ping({}, error_code);
		ws->control_callback([this](websocket::frame_type kind, boost::beast::string_view payload){
			boost::ignore_unused(kind, payload);
			log.debug("Heartbeat acknowledged.");
			lastHeartbeatAck = time(0);
		});
		// ws->write(net::buffer(message_string), error_code);
		if (error_code) {
			throw beast::system_error{error_code};
		}
		// log.debug("Message sent: " + message_string);
	});
}

json CPPGuilded::WSManager::get_heartbeat_payload() {
	// This method isn't used as Guilded only requires the default way of pinging.
	json heartbeatPayload = {
		{
			"op", 1
		}
	};
	if (lastMessageID != "UNDEFINED") heartbeatPayload["s"] = lastMessageID;
	return heartbeatPayload;
}