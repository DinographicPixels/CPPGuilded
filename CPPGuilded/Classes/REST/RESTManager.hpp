//
// Created by PakkoGraphic on 2/10/2023.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include <iostream>

#ifndef CPPGUILDED_RESTMANAGER_HPP
#define CPPGUILDED_RESTMANAGER_HPP

#include "static.hpp"
#include "Classes/RequestHandler.hpp"

#include "Routes/Channels.hpp"
#include "Routes/Guilds.hpp"
#include "Routes/Misc.hpp"

namespace CPPGuilded {
	class Client;
	class RESTManager {
	 protected:
		CPPGuilded::Client* client;
		std::shared_ptr<CPPGuilded::RequestHandler> manager;
	 public:
		std::unique_ptr<CPPGuilded::Channels> channels;
		std::unique_ptr<CPPGuilded::Guilds> guilds;
		std::unique_ptr<CPPGuilded::Misc> misc;
		RESTManager(CPPGuilded::Client* client);
	};
}

#endif
