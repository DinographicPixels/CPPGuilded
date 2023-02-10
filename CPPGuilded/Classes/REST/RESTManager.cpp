#include "RESTManager.hpp"

#include <iostream>
#include "static.hpp"

#include "Classes/RequestHandler.hpp"

CPPGuilded::RESTManager::RESTManager(CPPGuilded::Client* client): client(client) {
	this->manager = make_shared<RequestHandler>(client);
	this->channels = std::make_unique<Channels>(client, manager);
	this->guilds = std::make_unique<Guilds>(client, manager);
}

