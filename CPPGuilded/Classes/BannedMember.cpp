//
// Created by PakkoGraphic on 2/23/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "BannedMember.hpp"
#include <iostream>
#include "static.hpp"

#include "library.hpp"
#include "Classes/Exceptions.hpp"
#include "User.hpp"


CPPGuilded::BannedMember::BannedMember(const string& guildID, const json& data, Client* client): client(client), data(data)
{
	ban.guildID = guildID;
	if (!client->utils->has_value(data, "user")) throw CPPGuilded::GuildedException("Couldn't get user data from payload.");
	ban.userID = client->utils->get_or_else<std::string>(data.at("user"), "id", "");
	ban.reason = client->utils->get_optional<std::string>(data.at("user"), "reason");
	ban.createdBy = client->utils->get_or_else<std::string>(data.at("user"), "createdBy", "");
	ban.createdAt = client->utils->get_or_else<std::string>(data.at("user"), "createdAt", "");
}

CPPGuilded::User CPPGuilded::BannedMember::user()
{
	return User{data.at("user"), client};
}
