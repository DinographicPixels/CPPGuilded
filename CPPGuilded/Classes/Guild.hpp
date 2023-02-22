//
// Created by PakkoGraphic on 2/22/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#ifndef CPPGUILDED_GUILD_HPP
#define CPPGUILDED_GUILD_HPP

#include <iostream>
#include "static.hpp"

#include "Classes/Base.hpp"

namespace CPPGuilded
{
	class Client;
	class Guild: public Base<std::string>
	{
	 public:
		std::string ownerID;
		std::optional<std::string> type;
		std::string name;
		std::optional<std::string> url;
		std::optional<std::string> about;
		std::optional<std::string> avatarURL;
		std::optional<std::string> bannerURL;
		std::optional<std::string> timezone;
		std::optional<bool> isVerified;
		std::optional<std::string> defaultChannelID;
		std::string createdAt;

		Guild(const json& data, CPPGuilded::Client* client);
	};

} // CPPGuilded

#endif //CPPGUILDED_GUILD_HPP
