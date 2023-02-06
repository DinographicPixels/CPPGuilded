#include <iostream>
#include <map>
#include "static.hpp"
#include "library.hpp"

#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/log/core.hpp>

#include "Classes/Channel.hpp"
#include "Classes/Message.hpp"
#include "Classes/Utils.hpp"
#include "Classes/RequestHandler.hpp"
#include "Classes/GatewayHandler.hpp"


namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace ssl = net::ssl;
using tcp = net::ip::tcp;

CPPGuilded::Client::Client(string TOKEN){
    token = TOKEN;
    utils = std::make_unique<Utils>();
	rest = std::make_unique<RequestHandler>(this);
	log = Utils::Logger("Client | CPPGuilded");
	this->gatewayHandler = std::make_unique<GatewayHandler>(token);
}

bool CPPGuilded::Client::hello(bool sus) {
    json data = json();
    data["content"] = "TEST SUCCESS";
    CPPGuilded::RequestHandler::GuildedHTTPResponse reqRes = rest->request("POST", "/channels/b1df1cbb-9074-4692-b6a0-3997a47cacf1/messages", data.size() > 0 ? data.dump() : "");
    Message* sentMessage = new Message(json::parse(reqRes.body).at("message"), this);
    cout << sentMessage->type << endl;
    // Channel* retrievedChannel = new Channel (json::parse(reqRes.body).at("channel"));
    // std::cout << "here we go: " << retrievedChannel->id << std::endl;
    // std::cout << json::parse(reqRes.body).at("channel") << std::endl;
    if (sus == true){
        std::cout << "SUS" << std::endl;
    }else {
        std::cout << "Hello, World!" << std::endl;
    }
    return true;
};


CPPGuilded::Message* CPPGuilded::Client::createMessage(std::string channelID, CreateMessageOptions options) {
	Message::Embed* messageEmbed = new Message::Embed();
	messageEmbed->title = "embed testin'";
	messageEmbed->description = "this is a desc";
	messageEmbed->url = "https://touchguild.com";
	messageEmbed->fields = {{"field 1", "value 1", true}};
	CreateMessageOptions cringe = { "hi", { "0fbfb1eb-b884-42ec-a89d-253edd329997" }, false, false, {messageEmbed} };
	json jsonOptions = cringe;
	if (cringe.embeds.size() >= 1){
		for (auto x: cringe.embeds){
			json jsonEmbed = x->to_json();
			jsonOptions["embeds"].push_back(jsonEmbed);
		}
		// json jsonEmbed = json{*messageEmbed};
		//jsonOptions["embeds"] = jsonEmbed;
	}
	RequestHandler::GuildedHTTPResponse req = rest->request("POST", "/channels/" + channelID + "/messages", jsonOptions.dump());
	json res = json::parse(req.body).at("message");

	return new Message(res, this);
}
void CPPGuilded::Client::connect() {
	log.info("Connecting..");
	this->gatewayHandler->connect().get();
}
