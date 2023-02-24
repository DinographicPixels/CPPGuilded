//
// Created by PakkoGraphic on 2/23/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#include "static.hpp"
#include <iostream>

#ifndef CPPGUILDED_GUILDHANDLER_HPP
#define CPPGUILDED_GUILDHANDLER_HPP

namespace CPPGuilded
{
	class Client;
	class GuildHandler
	{
	 public:
		void guild_member_update(const json& data, Client* client);
		void guild_member_remove(const json& data, Client* client);
		void guild_member_ban(const json& data, Client* client);
		void guild_member_unban(const json& data, Client* client);
	};

} // CPPGuilded

#endif //CPPGUILDED_GUILDHANDLER_HPP
