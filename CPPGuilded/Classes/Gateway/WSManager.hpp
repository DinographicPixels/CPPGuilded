//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once
#include "static.hpp"

#include <boost/beast.hpp>

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>

#include <boost/asio/ssl.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>

#include <iostream>

#include "Classes/Utils.hpp"

#include <future>
#include <shared_mutex>
#include <thread>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace ssl = net::ssl;
namespace websocket = beast::websocket;
using tcp = net::ip::tcp;

namespace CPPGuilded {
	class Threadpool;
	class WSManager {
	  protected:
		Utils utils;
		Utils::Logger log;
		std::shared_ptr<Threadpool> threadpool;
		ssl::context ctx{ssl::context::tlsv13};
		net::io_context ioc;
		tcp::resolver resolver{ioc};
		std::unique_ptr<websocket::stream<beast::ssl_stream<tcp::socket>>> ws;
		unsigned int heartbeat_interval;
		bool connected;
		bool keepAlive;
		time_t lastHeartbeatAck;
		std::string lastMessageID;
		bool clientReady;
		unsigned int reconnectTimeout;
	  public:
		std::thread heartbeat_thread;
		DLL_EXPORT std::shared_future<void> send(const json& message);
		string token;
		DLL_EXPORT virtual shared_future<void> connect();
		DLL_EXPORT void startHeartbeating();
		DLL_EXPORT void on_websocket_message(const std::string& message);
		DLL_EXPORT json get_heartbeat_payload();
		DLL_EXPORT WSManager(const std::string& token, const std::shared_ptr<Threadpool>& threadpool);
		DLL_EXPORT virtual ~WSManager();
		DLL_EXPORT bool getState();
		DLL_EXPORT shared_future<void> TEST();
		DLL_EXPORT void on_websocket_disconnect();
		DLL_EXPORT shared_future<void> close();
		DLL_EXPORT virtual shared_future<void> ON_GATEWAY_PARSED_PACKET(const std::string& name, const json& data) = 0;
	};
}
