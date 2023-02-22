//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "Channel.hpp"
#include "static.hpp"
#include <iostream>

#include "library.hpp"

using namespace std;

CPPGuilded::Channel::Channel(const json& data, Client* client): Base<std::string>(
	client->utils->get_or_else<std::string>(data, "id", "")
	) {
	this->client = client;
	// Properties
	type = client->utils->get_or_else<std::string>(data, "type", "");
	name = client->utils->get_or_else<std::string>(data, "name", "");
	createdAt = client->utils->get_or_else<std::string>(data, "createdAt", "");
	createdBy = client->utils->get_or_else<std::string>(data, "createdBy", "");
	guildID = client->utils->get_or_else<std::string>(data, "guildID", "");
	groupID = client->utils->get_or_else<std::string>(data, "groupID", "");
	// Optional properties
	topic = client->utils->get_optional<std::string>(data, "topic");
	updatedAt = client->utils->get_optional<std::string>(data, "updatedAt");
	parentID = client->utils->get_optional<std::string>(data, "parentId");
	categoryID = client->utils->get_optional<std::string>(data, "categoryId");
	isPublic = client->utils->get_optional<bool>(data, "isPublic");
	archivedBy = client->utils->get_optional<std::string>(data, "archivedBy");
	archivedAt = client->utils->get_optional<std::string>(data, "archivedAt");
};

CPPGuilded::Channel CPPGuilded::Channel::edit(CPPGuilded::MethodOptions::EditChannel options)
{
	return client->rest.channels.edit_channel(id, options);
}

void CPPGuilded::Channel::delete_c()
{
	return client->rest.channels.delete_channel(id);
}