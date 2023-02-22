//
// Created by PakkoGraphic on 2/10/2023.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "Guilds.hpp"
#include <iostream>
#include "static.hpp"

#include "Classes/Member.hpp"
#include "Classes/RequestHandler.hpp"
#include "Classes/Guild.hpp"

CPPGuilded::Guilds::Guilds(CPPGuilded::Client* client, std::shared_ptr<CPPGuilded::RequestHandler> manager): client(client), manager(manager) {};

CPPGuilded::Member CPPGuilded::Guilds::get_member(std::string guildID, std::string memberID) {
	RequestHandler::GuildedHTTPResponse req = manager->request("GET", "/servers/" + guildID + "/members/" + memberID);
	json res = json::parse(req.body).at("member");
	return Member(res, client);
}

CPPGuilded::Guild CPPGuilded::Guilds::get_guild(std::string guildID)
{
	RequestHandler::GuildedHTTPResponse req = manager->request("GET", "/servers/" + guildID);
	json res = json::parse(req.body).at("server");
	return Guild(res, client);
}
