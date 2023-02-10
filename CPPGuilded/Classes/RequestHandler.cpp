//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "RequestHandler.hpp"
#include "static.hpp"
#include <iostream>

#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/log/core.hpp>

#include "library.hpp"

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace ssl = net::ssl;
using tcp = net::ip::tcp;

CPPGuilded::RequestHandler::RequestHandler(Client* client) {
	this->client = client;
}

CPPGuilded::RequestHandler::GuildedHTTPResponse CPPGuilded::RequestHandler::request(const string method, const string target, const string& data) {
	ssl::context ssl_context(ssl::context::tlsv13);
	ssl_context.set_verify_mode(ssl::verify_peer | boost::asio::ssl::verify_fail_if_no_peer_cert);
	load_ssl_certificates(ssl_context);

	net::io_context ioc;
	tcp::resolver resolver(ioc);
	auto const results = resolver.resolve(GUILDED_HOST, "https");
	ssl::stream<tcp::socket> stream(ioc, ssl_context);
	boost::asio::connect(stream.lowest_layer(), results);

	if (!SSL_set_tlsext_host_name(stream.native_handle(), GUILDED_HOST)){
		throw beast::system_error(
			beast::error_code(
				static_cast<int>(::ERR_get_error()),
				net::error::get_ssl_category()),
			"Failed to set SNI Hostname");
	}
	stream.handshake(ssl::stream_base::client);


	http::request<http::string_body> req{http::string_to_verb(method), "/api/v"+ to_string(GUILDED_APIVERSION) + target , 11};
	// http::request<http::string_body>{http::string_to_verb("GET"), "https://www.guilded.gg/api/v1/channels/b1df1cbb-9074-4692-b6a0-3997a47cacf1", 1};
	req.set(http::field::host, GUILDED_HOST);
	req.set(http::field::user_agent, "TEST");
	req.set(http::field::content_type, "application/json");
	req.set(http::field::authorization, "Bearer " + this->client->token);
	req.set(http::field::connection, "Close");

	if (data.length() > 0){
		req.set(http::field::content_type, "application/json");
		req.set(http::field::content_length, to_string(data.length()));
		req.body() = data;
	}

	std::cout << req << std::endl;
	// req.set(boost::beast::http::field::body, {""});

	http::write(stream, req);

	beast::flat_buffer buffer;
	http::response<http::string_body> res;

	http::read(stream, buffer, res);
	std::cout << res << std::endl;

	beast::error_code errCode;
	stream.shutdown(errCode);
	if (errCode && errCode != beast::errc::not_connected && errCode != boost::asio::error::eof && errCode != boost::asio::ssl::error::stream_truncated) {
		throw beast::system_error{errCode};
	}

	std::map<std::string, std::string> resHeaders;
	for (auto it = res.base().begin(); it != res.base().end(); it++) {
		resHeaders.emplace(it->name_string(), it->value());
	}

	return GuildedHTTPResponse{res.result_int(), resHeaders, res.body()};
};