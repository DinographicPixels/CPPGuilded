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
		std::shared_ptr<CPPGuilded::RequestHandler> manager = make_shared<RequestHandler>(client);;
	 public:
		CPPGuilded::Channels channels;
		CPPGuilded::Guilds guilds;
		CPPGuilded::Misc misc;
		RESTManager(CPPGuilded::Client* client);
	};
}

#endif
