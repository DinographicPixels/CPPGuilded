//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "MessageHandler.hpp"
#include "static.hpp"
#include "library.hpp"
#include "Classes/Message.hpp"

void CPPGuilded::MessageHandler::message_create(const json& data, Client* client) {
	std::cout << "a message has been created" << std::endl;
	Message message = Message(data.at("message"), client);
	client->on_message_create(message);
};

void CPPGuilded::MessageHandler::message_update(const json& data, Client* client) {
	std::cout << "a message has been edited" << std::endl;
	Message message = Message(data.at("message"), client);
	client->on_message_update(message);
};

void CPPGuilded::MessageHandler::message_delete(const json& data, Client* client) {
	std::cout << "a message has been deleted" << std::endl;
	Message message = Message(data.at("message"), client);
	client->on_message_delete(message);
};