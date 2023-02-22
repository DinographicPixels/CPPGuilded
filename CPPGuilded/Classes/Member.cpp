//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "Member.hpp"
#include <iostream>
#include "static.hpp"

CPPGuilded::Member::Member(const json& data, Client* client): User(data.at("user"), client) {
	// Properties
	this->roleIDs = client->utils->get_or_else<std::vector<int>>(data, "roleIds", {});
	this->joinedAt = client->utils->get_or_else<std::string>(data, "joinedAt", "");
	// Optional properties
	this->nickname = client->utils->get_optional<std::string>(data, "nickname");
	this->isOwner = client->utils->get_optional<bool>(data, "isOwner");
}
