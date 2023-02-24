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
		/** Client  */
		CPPGuilded::Client* client;
		/** RequestHandler used to execute HTTPS requests. */
		std::shared_ptr<CPPGuilded::RequestHandler> manager = make_shared<RequestHandler>(client);;
	 public:
		/**
		 * REST Methods related to channels.
		 */
		CPPGuilded::Channels channels;
		/**
		 * REST Methods related to guilds.
		 */
		CPPGuilded::Guilds guilds;
		/**
		 * REST Methods related to neither channels and guilds.
		 */
		CPPGuilded::Misc misc;
		/**
		 * RESTManager's constructor.
		 * @param client Client.
		 */
		DLL_EXPORT RESTManager(CPPGuilded::Client* client);
	};
}

#endif
