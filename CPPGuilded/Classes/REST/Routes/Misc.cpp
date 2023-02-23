//
// Created by PakkoGraphic on 2/20/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "Misc.hpp"

#include <iostream>
#include "static.hpp"

#include "Classes/User.hpp"

CPPGuilded::Misc::Misc(CPPGuilded::Client* client, std::shared_ptr<CPPGuilded::RequestHandler> manager): client(client), manager(std::move(manager)) {};

CPPGuilded::User CPPGuilded::Misc::get_user(const std::string& userID)
{
	RequestHandler::GuildedHTTPResponse req = this->manager->request("GET", "/users/" + userID);
	json res = json::parse(req.body).at("user");
	return User{res, client};
};