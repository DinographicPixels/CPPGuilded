#include <iostream>

#ifndef CPPGUILDED_RESTMANAGER_HPP
#define CPPGUILDED_RESTMANAGER_HPP

#include "static.hpp"
#include "Classes/RequestHandler.hpp"

#include "Routes/Channels.hpp"
#include "Routes/Guilds.hpp"

namespace CPPGuilded {
	class Client;
	class RESTManager {
	 protected:
		CPPGuilded::Client* client;
		std::shared_ptr<CPPGuilded::RequestHandler> manager;
	 public:
		std::unique_ptr<CPPGuilded::Channels> channels;
		std::unique_ptr<CPPGuilded::Guilds> guilds;
		RESTManager(CPPGuilded::Client* client);
	};
}

#endif
