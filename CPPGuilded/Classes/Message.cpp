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

CPPGuilded::Message::Message(const json &data, Client* client): client(client) {
    id = client->utils->get_value<std::string>(data, "id");
    type = client->utils->get_value<std::string>(data, "type");
    guildID = client->utils->get_value<std::string>(data, "serverId");
    channelID = client->utils->get_value<std::string>(data, "channelId");
    content = client->utils->get_value<std::string>(data, "content");
    embeds = client->utils->get_value<vector<Embed>>(data, "embeds");
    replyMessageIDs = client->utils->get_value<vector<string>>(data, "replyMessageIds");
    isPrivate = client->utils->get_value<bool>(data, "isPrivate");
    isSilent = client->utils->get_value<bool>(data, "isSilent");
    mentions = client->utils->get_value<std::string>(data, "mentions");
    createdAt = client->utils->get_value<std::string>(data, "createdAt");
    createdBy = client->utils->get_value<std::string>(data, "createdBy");
    createdByWebhookID = client->utils->get_value<std::string>(data, "createdByWebhookId");
    updatedAt = client->utils->get_value<std::string>(data, "updatedAt");
}


CPPGuilded::Message CPPGuilded::Message::create_message(CPPGuilded::MethodOptions::CreateMessage options)
{
	return client->rest->channels->create_message(channelID, options);
}

CPPGuilded::Message CPPGuilded::Message::edit_message(CPPGuilded::MethodOptions::EditMessage options)
{
	return client->rest->channels->edit_message(channelID, id, options);
}

void CPPGuilded::Message::delete_message()
{
	client->rest->channels->delete_message(channelID, id);
}
