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

CPPGuilded::GatewayHandler::GatewayHandler(Client* client)
	: CPPGuilded::WSManager(client->token, std::make_shared<Threadpool>(std::thread::hardware_concurrency())), client(client) {
	this->token = WSManager::token;
	this->message_handler = std::make_unique<CPPGuilded::MessageHandler>();
}

shared_future<void> CPPGuilded::GatewayHandler::ON_GATEWAY_PARSED_PACKET(const std::string& name, const json& data) {
	return threadpool->execute([this, name, data](){
		std::unordered_map<std::string, std::function<void(json)>> toHandlerMap = {
			{ "ChatMessageCreated", [&](const json& data){ message_handler->messageCreate(data, client); } },
			{ "ChatMessageUpdated", [&](const json& data){ message_handler->messageUpdate(data, client); } },
			{ "ChatMessageDeleted", [&](const json& data) { message_handler->messageDelete(data, client); } }
		};
		std::cout << "event name: " << name << std::endl;
		std::cout << "data: " << data << std::endl;
		if (toHandlerMap.count(name) > 0) std::cout << "HANDLER CALLED" << std::endl; toHandlerMap.at(name)(data);
	});
}

std::shared_future<void> CPPGuilded::GatewayHandler::connect() {
	return WSManager::connect();
}