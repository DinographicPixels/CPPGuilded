//
// Created by PakkoGraphic on 2/23/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "GuildHandler.hpp"
#include "static.hpp"
#include <iostream>

#include "Classes/Member.hpp"
#include "Classes/BannedMember.hpp"
#include "Classes/REST/Definitions.hpp"

void CPPGuilded::GuildHandler::guild_member_update(const json& data, Client* client)
{
	std::cout << "guild_member_update fired." << std::endl;
	CPPGuilded::Models::MemberUpdateInfo memberInfo = CPPGuilded::Models::MemberUpdateInfo(data);
	client->on_guild_member_update(memberInfo);
}

void CPPGuilded::GuildHandler::guild_member_remove(const json& data, Client* client)
{
	std::cout << "guild_member_remove fired." << std::endl;
	CPPGuilded::Models::MemberRemoveInfo memberInfo = CPPGuilded::Models::MemberRemoveInfo(data);
	client->on_guild_member_remove(memberInfo);
}

void CPPGuilded::GuildHandler::guild_member_ban(const json& data, Client* client)
{
	std::cout << "guild_member_ban fired." << std::endl;
	CPPGuilded::BannedMember bannedMember = CPPGuilded::BannedMember(data.at("serverId"), data.at("serverMemberBan"), client);
	client->on_guild_member_ban(bannedMember);
}

void CPPGuilded::GuildHandler::guild_member_unban(const json& data, Client* client)
{
	std::cout << "guild_member_unban fired." << std::endl;
	CPPGuilded::BannedMember bannedMember = CPPGuilded::BannedMember(data.at("serverId"), data.at("serverMemberBan"), client);
	client->on_guild_member_unban(bannedMember);
}