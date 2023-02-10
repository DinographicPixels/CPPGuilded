#pragma once

#ifndef CPPGUILDED_USER_HPP
#define CPPGUILDED_USER_HPP

#include <iostream>

#include "static.hpp"
#include "library.hpp"

namespace CPPGuilded {
	class User {
	 public:
		std::string id;
		std::string type;
		std::string username;
		std::string avatarURL;
		User(const json& data, Client* client);
	};

}

#endif
