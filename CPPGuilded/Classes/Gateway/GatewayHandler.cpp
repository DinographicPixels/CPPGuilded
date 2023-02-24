//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "GatewayHandler.hpp"
#include "static.hpp"

#include <iostream>
#include <future>
#include <thread>
#include <stdio.h>

#include <vector>
#include <stdlib.h>
#include <time.h>

#include "library.hpp"
#include "Classes/Threadpool.hpp"
#include "Events/MessageHandler.hpp"
#include "Events/ChannelHandler.hpp"
#include "Events/GuildHandler.hpp"
#include "Events/ForumThreadHandler.hpp"

CPPGuilded::GatewayHandler::GatewayHandler(Client* client)
	: CPPGuilded::WSManager(client->token, std::make_shared<Threadpool>(std::thread::hardware_concurrency())), client(client) {
	this->token = WSManager::token;
	this->messageHandler = std::make_unique<CPPGuilded::MessageHandler>();
	this->channelHandler = std::make_unique<CPPGuilded::ChannelHandler>();
	this->guildHandler = std::make_unique<CPPGuilded::GuildHandler>();
	this->forumThreadHandler = std::make_unique<CPPGuilded::ForumThreadHandler>();
}

shared_future<void> CPPGuilded::GatewayHandler::ON_GATEWAY_PARSED_PACKET(const std::string& name, const json& data) {
	return threadpool->execute([this, name, data](){
		std::unordered_map<std::string, std::function<void(json)>> toHandlerMap = {
			{ "ChatMessageCreated",   [&](const json& data) { messageHandler->message_create(data, client);          } },
			{ "ChatMessageUpdated",   [&](const json& data) { messageHandler->message_update(data, client);          } },
			{ "ChatMessageDeleted",   [&](const json& data) { messageHandler->message_delete(data, client);          } },
			{ "ServerChannelCreated", [&](const json& data) { channelHandler->channel_create(data, client);    	   } },
			{ "ServerChannelUpdated", [&](const json& data) { channelHandler->channel_update(data, client);    	   } },
			{ "ServerChannelDeleted", [&](const json& data) { channelHandler->channel_delete(data, client);    	   } },
			{ "ServerMemberUpdated",  [&](const json& data) { guildHandler->guild_member_update(data, client); 	   } },
			{ "ServerMemberRemoved",  [&](const json& data) { guildHandler->guild_member_update(data, client);	   } },
			{ "ServerMemberBanned",   [&](const json& data) { guildHandler->guild_member_ban(data, client);   	   } },
			{ "ServerMemberUnbanned", [&](const json& data) { guildHandler->guild_member_unban(data, client);        } },
			{ "ForumTopicCreated",    [&](const json& data) { forumThreadHandler->forum_thread_create(data, client); } },
			{ "ForumTopicUpdated",    [&](const json& data) { forumThreadHandler->forum_thread_update(data, client); } },
			{ "ForumTopicDeleted",    [&](const json& data) { forumThreadHandler->forum_thread_delete(data, client); } }
		};
		std::cout << "event name: " << name << std::endl;
		std::cout << "data: " << data.dump(4, ' ') << std::endl;
		if (data.contains("message") && data.at("message").value("type", "UNDEFINED") == "system") return;
		if (toHandlerMap.count(name) > 0) std::cout << "HANDLER CALLED" << std::endl; toHandlerMap.at(name)(data);
	});
}

std::shared_future<void> CPPGuilded::GatewayHandler::connect() {
	return WSManager::connect();
}