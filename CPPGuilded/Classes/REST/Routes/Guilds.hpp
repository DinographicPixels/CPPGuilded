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
		/**
		 * Get a guild member.
		 * @param guildID ID of the guild the member is in.
		 * @param memberID ID of the member to get.
		 * @return Member
		 */
		CPPGuilded::Member get_member(const std::string& guildID, const std::string& memberID);
		/**
		 * Get every members from a guild.
		 * @param guildID ID of the guild the members are in.
		 * @return vector<Member>
		 */
		vector<CPPGuilded::Member> get_members(const std::string& guildID);
		/**
		 * Get a guild (aka server).
		 * @param guildID ID of the guild to get.
		 * @return Guild
		 */
		CPPGuilded::Guild get_guild(const std::string& guildID);
		/**
		 * Change a member's nickname.
		 * @param guildID ID of the guild the member is in.
		 * @param memberID ID of the member.
		 * @param nickname New member's in-guild nickname.
		 * @return std::string (nickname)
		 */
		std::string change_member_nickname(const std::string& guildID, const std::string& memberID, const std::string& nickname);
		/**
		 * Remove the nickname of a guild member.
		 * @param guildID ID of the guild the member is in.
		 * @param memberID ID of the member.
		 */
		void remove_member_nickname(const std::string& guildID, const std::string& memberID);
		/**
		 * Kick/remove a member from a guild.
		 * @param guildID ID of a guild the member is in.
		 * @param memberID ID of the member to kick.
		 */
		void remove_member(const std::string& guildID, const std::string& memberID);
		/**
		 * Ban a guild member.
		 * @param guildID ID of the guild the member to ban is in.
		 * @param memberID ID of the member to ban.
		 * @param reason The reason of the ban. (optional)
		 * @return BannedMember
		 */
		CPPGuilded::BannedMember create_ban(const std::string& guildID, const std::string& memberID, const std::optional<std::string>& reason);
		/**
		 * Unban a guild member.
		 * @param guildID ID of the guild, where the member was banned.
		 * @param memberID ID of the member to unban.
		 */
		void remove_ban(const std::string& guildID, const std::string& memberID);
		/**
		 * Get a guild member ban.
		 * @param guildID ID of the guild the member is banned.
		 * @param memberID ID of the banned member.
		 * @return BannedMember
		 */
		CPPGuilded::BannedMember get_ban(const std::string& guildID, const std::string& memberID);
		/**
		 * Get every bans from a guild.
		 * @param guildID ID of the guild.
		 * @return vector<BannedMember>
		 */
		vector<CPPGuilded::BannedMember> get_bans(const std::string& guildID);
	};
}

#endif //CPPGUILDED_GUILDS_HPP
