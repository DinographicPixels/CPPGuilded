#include "MessageHandler.hpp"
#include "static.hpp"
#include "library.hpp"
#include "Classes/Message.hpp"

void CPPGuilded::MessageHandler::messageCreate(const json& data, Client* client) {
	std::cout << "a message has been created" << std::endl;
	Message message = Message(data.at("message"), client);
	client->on_message_create(message);
};

void CPPGuilded::MessageHandler::messageUpdate(const json& data, Client* client) {
	std::cout << "a message has been edited" << std::endl;
	Message message = Message(data.at("message"), client);
	client->on_message_update(message);
};

void CPPGuilded::MessageHandler::messageDelete(const json& data, Client* client) {
	std::cout << "a message has been deleted" << std::endl;
	Message message = Message(data.at("message"), client);
	client->on_message_delete(message);
};