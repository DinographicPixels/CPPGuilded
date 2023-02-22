//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#ifndef CPPGUILDED_USER_HPP
#define CPPGUILDED_USER_HPP

#include <iostream>

#include "static.hpp"
#include "library.hpp"
#include "Base.hpp"

namespace CPPGuilded {
	class User : public Base<std::string> {
	 public:
		std::string type;
		std::string username;
		std::optional<std::string> avatarURL;
		std::optional<std::string> bannerURL;
		bool bot;
		User(const json& data, Client* client);
	};

}

#endif
