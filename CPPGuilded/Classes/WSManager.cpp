#include "WSManager.hpp"
#include "static.hpp"

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <future>

#include <iostream>

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>

#include <boost/asio/ssl.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace ssl = net::ssl;
namespace websocket = beast::websocket;
using tcp = net::ip::tcp;

CPPGuilded::WSManager::WSManager(const std::string& token) {
	try{
		ssl::context ctx{ssl::context::tlsv13};
		net::io_context ioc;
		tcp::resolver resolver{ioc};
		websocket::stream<beast::ssl_stream<tcp::socket>> ws{ioc, ctx};

		if (!SSL_set_tlsext_host_name(ws.next_layer().native_handle(), GUILDED_HOST)) {
			throw beast::system_error(beast::error_code(static_cast<int>(::ERR_get_error()), net::error::get_ssl_category()),
				"Failed to set SNI Hostname");
		}

		auto const results = resolver.resolve(GUILDED_HOST, "443");
		net::connect(ws.next_layer().next_layer(), results.begin(), results.end());
		ws.next_layer().handshake(ssl::stream_base::server);
		ws.handshake(GUILDED_HOST, "/websocket/v" + to_string(GUILDED_APIVERSION));

		beast::flat_buffer buffer;
		ws.read(buffer);
		std::cout << beast::make_printable(buffer.data()) << std::endl;
	} catch(std::exception const& err){
		std::cout << "ws err: " << err.what() << std::endl;
	}
}