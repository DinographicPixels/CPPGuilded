//
// Created by PakkoGraphic on 2/20/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#ifndef CPPGUILDED_MISC_HPP
#define CPPGUILDED_MISC_HPP

#include <iostream>
#include "static.hpp"

#include "Classes/RequestHandler.hpp"

namespace CPPGuilded {
	class User;
	class Misc {
	 protected:
		CPPGuilded::Client* client;
		std::shared_ptr<CPPGuilded::RequestHandler> manager;
	 public:
		Misc(CPPGuilded::Client* client, std::shared_ptr<CPPGuilded::RequestHandler> manager);
		/**
		 * Get a user.
 		 * @param userID The ID of a Guilded user.
 		 * @return User
 		*/
		CPPGuilded::User get_user(const std::string& userID);
	};
}

#endif //CPPGUILDED_MISC_HPP
