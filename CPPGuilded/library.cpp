//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

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
#include "Classes/REST/RESTManager.hpp"


namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace ssl = net::ssl;
using tcp = net::ip::tcp;

CPPGuilded::Client::Client(string token){
    this->token = token;
    this->utils = std::make_unique<Utils>();
	this->rest = std::make_unique<RESTManager>(this);
	this->log = Utils::Logger("Client | CPPGuilded");
	this->gatewayHandler = std::make_shared<GatewayHandler>(this);
}

bool CPPGuilded::Client::hello(bool sus) {
    json data = json();
    data["content"] = "TEST SUCCESS";
    //here CPPGuilded::RequestHandler::GuildedHTTPResponse reqRes = request->("POST", "/channels/b1df1cbb-9074-4692-b6a0-3997a47cacf1/messages", data.size() > 0 ? data.dump() : "");
    //here Message* sentMessage = new Message(json::parse(reqRes.body).at("message"), this);
    //here cout << sentMessage->type << endl;
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

void CPPGuilded::Client::connect() {
	log.info("Connecting..");
	srand((unsigned int)time(NULL));
	this->gatewayHandler->connect();
}

CPPGuilded::Message CPPGuilded::Client::create_message(std::string channelID,
	CPPGuilded::MethodOptions::CreateMessage options)
{
	return rest->channels->create_message(channelID, options);
}

CPPGuilded::Message CPPGuilded::Client::edit_message(std::string channelID,
	std::string messageID,
	CPPGuilded::MethodOptions::EditMessage options)
{
	return rest->channels->edit_message(channelID, messageID, options);
}

void CPPGuilded::Client::delete_message(std::string channelID, std::string messageID)
{
	return rest->channels->delete_message(channelID, messageID);
}

CPPGuilded::Member CPPGuilded::Client::get_member(std::string guildID, std::string memberID)
{
	return rest->guilds->get_member(guildID, memberID);
}

CPPGuilded::Message CPPGuilded::Client::get_message(std::string channelID, std::string messageID)
{
	return rest->channels->get_message(channelID, messageID);
}

std::vector<CPPGuilded::Message> CPPGuilded::Client::get_messages(std::string channelID,
	CPPGuilded::MethodFilters::GetChannelMessages filter)
{
	return rest->channels->get_messages(channelID, filter);
}

CPPGuilded::User CPPGuilded::Client::get_user(const std::string& userID)
{
	return rest->misc->get_user(userID);
}


// EVENTS
void CPPGuilded::Client::on_message_create(CPPGuilded::Message message) {};
void CPPGuilded::Client::on_message_update(CPPGuilded::Message message) {};
void CPPGuilded::Client::on_message_delete(CPPGuilded::Message message) {};
