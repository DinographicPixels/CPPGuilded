//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "Message.hpp"
#include "static.hpp"
#include <iostream>

#include "Exceptions.hpp"

#include "library.hpp"
#include "REST/Definitions.hpp"
#include "Embed.hpp"

CPPGuilded::Message::Message(const json &data, Client* client): Base<std::string>(
	client->utils->get_or_else<std::string>(data, "id", "")
	), client(client) {
	// Properties
    type = client->utils->get_or_else<std::string>(data, "type", "");
    channelID = client->utils->get_or_else<std::string>(data, "channelId", "");
    replyMessageIDs = client->utils->get_or_else<vector<string>>(data, "replyMessageIds", {});
    createdAt = client->utils->get_or_else<std::string>(data, "createdAt", "");
    createdBy = client->utils->get_or_else<std::string>(data, "createdBy", "");
	if (client->utils->has_value(data, "embeds")){
		for (json embed : data.at("embeds")) {
			embeds.push_back(CPPGuilded::Embed(embed));
		};
	}
	// Optional properties
	guildID = client->utils->get_optional<std::string>(data, "serverId");
	content = client->utils->get_optional<std::string>(data, "content");
	isPrivate = client->utils->get_optional<bool>(data, "isPrivate");
	isSilent = client->utils->get_optional<bool>(data, "isSilent");
	std::cout << client->utils->get_optional<json>(data, "mentions")->dump(4, ' ') << std::endl;
	createdByWebhookID = client->utils->get_optional<std::string>(data, "createdByWebhookId");
	updatedAt = client->utils->get_optional<std::string>(data, "updatedAt");
	if (client->utils->has_value(data, "mentions")){
		mentions = CPPGuilded::Models::APIMentions(data.at("mentions"));
	}
}


CPPGuilded::Message CPPGuilded::Message::create_message(CPPGuilded::MethodOptions::CreateMessage options)
{
	return client->rest.channels.create_message(channelID, options);
}

CPPGuilded::Message CPPGuilded::Message::edit_message(CPPGuilded::MethodOptions::EditMessage options)
{
	return client->rest.channels.edit_message(channelID, id, options);
}

void CPPGuilded::Message::delete_m()
{
	client->rest.channels.delete_message(channelID, id);
}
