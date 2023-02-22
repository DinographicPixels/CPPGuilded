//
// Created by PakkoGraphic on 2/22/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "Guild.hpp"
#include "static.hpp"
#include <iostream>

#include "library.hpp"

CPPGuilded::Guild::Guild(const json& data, CPPGuilded::Client* client) : Base<std::string>(
	client->utils->get_or_else<std::string>(data, "id", "")
	)
{
	// Properties
	this->name = client->utils->get_or_else<std::string>(data, "name", "");
	this->ownerID = client->utils->get_or_else<std::string>(data, "ownerId", "");
	this->createdAt = client->utils->get_or_else<std::string>(data, "createdAt", "");
	// Optional properties
	this->type = client->utils->get_optional<std::string>(data, "type");
	this->url = client->utils->get_optional<std::string>(data, "url");
	this->about = client->utils->get_optional<std::string>(data, "about");
	this->avatarURL = client->utils->get_optional<std::string>(data, "avatar");
	this->bannerURL = client->utils->get_optional<std::string>(data, "banner");
	this->timezone = client->utils->get_optional<std::string>(data, "timezone");
	this->isVerified = client->utils->get_optional<bool>(data, "isVerified");
	this->defaultChannelID = client->utils->get_optional<std::string>(data, "defaultChannelId");
}