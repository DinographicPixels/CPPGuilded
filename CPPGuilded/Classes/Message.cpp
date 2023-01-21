#include "Message.hpp"
#include "static.hpp"
#include <iostream>

#include "Exceptions.hpp"

// #include "library.hpp"

CPPGuilded::Message::Message(json &data, Client* client) {
    id = data.at("id").get<string>();
    type = client->utils->getValue<std::string>(data, "type");
    serverID = data.at("serverId").get<string>();
    channelID = data.at("channelId").get<string>();
    content = data.at("content").get<string>();
    embeds = data.value("embeds", "UNDEFINED");
    replyMessageIDs = data.value("replyMessageIds", "UNDEFINED");
    isPrivate = data.value("isPrivate", false);
    isSilent = data.value("isSilent", false);
    mentions = data.value("mentions", "UNDEFINED");
    createdAt = data.at("createdAt").get<string>();
    createdBy = data.at("createdBy").get<string>();
    createdByWebhookID = data.value("createdByWebhookId", "UNDEFINED");
    updatedAt = data.value("updatedAt", "UNDEFINED");
}