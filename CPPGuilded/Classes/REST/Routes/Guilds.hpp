//
// Created by PakkoGraphic on 2/10/2023.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include <iostream>

#ifndef CPPGUILDED_GUILDS_HPP
#define CPPGUILDED_GUILDS_HPP

#include "static.hpp"

namespace CPPGuilded {
	class Client;
	class RequestHandler;
	class Member;
	class Guild;
	class BannedMember;
	class Guilds {
	 protected:
		CPPGuilded::Client* client;
		std::shared_ptr<CPPGuilded::RequestHandler> manager;
	 public:
		Guilds(CPPGuilded::Client* client, std::shared_ptr<CPPGuilded::RequestHandler> manager);
		CPPGuilded::Member get_member(const std::string& guildID, const std::string& memberID);
		vector<CPPGuilded::Member> get_members(const std::string& guildID);
		CPPGuilded::Guild get_guild(const std::string& guildID);
		std::string change_member_nickname(const std::string& guildID, const std::string& memberID, const std::string& nickname);
		void delete_member_nickname(const std::string& guildID, const std::string& memberID);
		void remove_member(const std::string& guildID, const std::string& memberID);
		CPPGuilded::BannedMember create_ban(const std::string& guildID, const std::string& memberID, const std::optional<std::string>& reason);
		void remove_ban(const std::string& guildID, const std::string& memberID);
		CPPGuilded::BannedMember get_ban(const std::string& guildID, const std::string& memberID);
		vector<CPPGuilded::BannedMember> get_bans(const std::string& guildID);
	};
}

#endif //CPPGUILDED_GUILDS_HPP
