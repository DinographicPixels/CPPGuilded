//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "User.hpp"
#include "static.hpp"
#include <iostream>

CPPGuilded::User::User(const json& data, Client* client): Base<std::string>(
	client->utils->get_or_else<std::string>(data, "id", "")
	) {
	// Properties
	this->type = client->utils->get_or_else<std::string>(data, "type", "UNDEFINED");
	this->username = client->utils->get_or_else<std::string>(data, "name", "");
	if (this->type == "UNDEFINED") this->type = "user";
	this->bot = this->type == "bot" ? true : false;

	// Optional properties
	this->avatarURL = client->utils->get_optional<std::string>(data, "avatar");
	this->bannerURL = client->utils->get_optional<std::string>(data, "banner");
}
