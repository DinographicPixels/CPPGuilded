//
// Created by PakkoGraphic on 2/23/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#include <iostream>
#include "static.hpp"

#ifndef CPPGUILDED_BANNEDMEMBER_HPP
#define CPPGUILDED_BANNEDMEMBER_HPP

namespace CPPGuilded
{
	class Client;
	class User;
	class Member;
	class BannedMember
	{
	 private:
		Client* client;
		const json& data;
	 protected:
		struct RegisteredBan {
			std::string userID;
			std::string guildID;
			std::optional<std::string> reason;
			std::string createdBy;
			std::string createdAt;
		};
	 public:
		RegisteredBan ban;
		User user();
		BannedMember(const string& guildID, const json& data, Client* client);
	};

} // CPPGuilded

#endif //CPPGUILDED_BANNEDMEMBER_HPP
