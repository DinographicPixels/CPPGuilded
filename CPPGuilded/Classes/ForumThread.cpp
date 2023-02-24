//
// Created by PakkoGraphic on 2/24/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "ForumThread.hpp"
#include "static.hpp"
#include <iostream>

#include "library.hpp"

CPPGuilded::ForumThread::ForumThread(const json& data, Client* client): Base<int>(
	client->utils->get_or_else<int>(data, "id", NAN)
	)
{
	// Properties
	this->guildID = client->utils->get_or_else<std::string>(data, "serverId", "");
	this->channelID = client->utils->get_or_else<std::string>(data, "channelId", "");
	this->title = client->utils->get_or_else<std::string>(data, "title", "");
	this->createdAt = client->utils->get_or_else<std::string>(data, "createdAt", "");
	this->createdBy = client->utils->get_or_else<std::string>(data, "createdBy", "");
	this->isPinned = client->utils->get_or_else<bool>(data, "isPinned", false);
	this->isLocked = client->utils->get_or_else<bool>(data, "isLocked", false);
	this->content = client->utils->get_or_else<std::string>(data, "content", "");
	if (client->utils->has_value(data, "mentions")){
		this->mentions = CPPGuilded::Models::APIMentions(data.at("mentions"));
	}
	// Optional properties
	this->updatedAt = client->utils->get_optional<std::string>(data, "updatedAt");
	this->bumpedAt = client->utils->get_optional<std::string>(data, "bumpedAt");
}