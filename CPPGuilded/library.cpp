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
#include "Classes/Gateway/GatewayHandler.hpp"
#include "Classes/Member.hpp"


namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace ssl = net::ssl;
using tcp = net::ip::tcp;

CPPGuilded::Client::Client(string token){
    this->token = token;
    this->utils = std::make_unique<Utils>();
	this->rest = std::make_unique<RequestHandler>(this);
	this->log = Utils::Logger("Client | CPPGuilded");
	this->gatewayHandler = std::make_shared<GatewayHandler>(this);
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


CPPGuilded::Message CPPGuilded::Client::create_message(std::string channelID, CreateMessageOptions options) {
	json jsonOptions = options;
	if (options.replyMessageIds.empty()) jsonOptions.erase("replyMessageIds");
	if (options.embeds.size() >= 1){
		for (auto x: options.embeds){
			json jsonEmbed = x.to_json();
			jsonOptions["embeds"].push_back(jsonEmbed);
		}
		// json jsonEmbed = json{*messageEmbed};
		//jsonOptions["embeds"] = jsonEmbed;
	}
	RequestHandler::GuildedHTTPResponse req = rest->request("POST", "/channels/" + channelID + "/messages", jsonOptions.dump());
	json res = json::parse(req.body).at("message");

	return Message(res, this);
}

CPPGuilded::Message CPPGuilded::Client::edit_message(std::string channelID, std::string messageID, EditMessageOptions options) {
	json jsonOptions = options;
	if (options.embeds.size() >= 1) {
		for (auto x: options.embeds){
			json jsonEmbed = x.to_json();
			jsonOptions["embeds"].push_back(jsonEmbed);
		}
	}
	RequestHandler::GuildedHTTPResponse req = rest->request("PUT", "/channels/" + channelID + "/messages/" + messageID, jsonOptions.dump());
	json res = json::parse(req.body).at("message");

	return Message(res, this);
}

void CPPGuilded::Client::delete_message(std::string channelID, std::string messageID) {
	rest->request("DELETE", "/channels/" + channelID + "/messages/" + messageID);
}

CPPGuilded::Member CPPGuilded::Client::get_member(std::string guildID, std::string memberID) {
	RequestHandler::GuildedHTTPResponse req = rest->request("GET", "/servers/" + guildID + "/members/" + memberID);
	json res = json::parse(req.body).at("member");
	return Member(res, this);
}

void CPPGuilded::Client::connect() {
	log.info("Connecting..");
	srand((unsigned int)time(NULL));
	this->gatewayHandler->connect();
}

void CPPGuilded::Client::on_message_create(CPPGuilded::Message message) {};
void CPPGuilded::Client::on_message_update(CPPGuilded::Message message) {};
void CPPGuilded::Client::on_message_delete(CPPGuilded::Message message) {};
