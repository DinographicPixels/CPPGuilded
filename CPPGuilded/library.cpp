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
#include "Classes/BannedMember.hpp"
#include "Classes/ForumThread.hpp"


namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
namespace ssl = net::ssl;
using tcp = net::ip::tcp;

CPPGuilded::Client::Client(string token): token(std::move(token)), rest(RESTManager(this)) {
    this->utils = std::make_unique<Utils>();
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
    if (sus){
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


// EVENTS
void CPPGuilded::Client::on_message_create(CPPGuilded::Message message) {};
void CPPGuilded::Client::on_message_update(CPPGuilded::Message message) {};
void CPPGuilded::Client::on_message_delete(CPPGuilded::Message message) {};
void CPPGuilded::Client::on_channel_create(CPPGuilded::Channel channel) {};
void CPPGuilded::Client::on_channel_update(CPPGuilded::Channel channel) {};
void CPPGuilded::Client::on_channel_delete(CPPGuilded::Channel channel) {};
void CPPGuilded::Client::on_guild_member_update(CPPGuilded::Models::MemberUpdateInfo memberUpdateInfo) {};
void CPPGuilded::Client::on_guild_member_remove(CPPGuilded::Models::MemberRemoveInfo memberRemoveInfo) {};
void CPPGuilded::Client::on_guild_member_ban(CPPGuilded::BannedMember bannedMember) {} ;
void CPPGuilded::Client::on_guild_member_unban(CPPGuilded::BannedMember bannedMember) {};
void CPPGuilded::Client::on_forum_thread_create(CPPGuilded::ForumThread forumThread) {};
void CPPGuilded::Client::on_forum_thread_update(CPPGuilded::ForumThread forumThread) {};
void CPPGuilded::Client::on_forum_thread_delete(CPPGuilded::ForumThread forumThread) {};

