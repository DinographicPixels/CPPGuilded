#include "Message.hpp"
#include "static.hpp"
#include <iostream>

#include "Exceptions.hpp"

#include "library.hpp"

CPPGuilded::Message::Message(json &data, Client* client) {
    id = client->utils->getValue<std::string>(data, "id");
    type = client->utils->getValue<std::string>(data, "type");
    serverID = client->utils->getValue<std::string>(data, "serverId");
    channelID = client->utils->getValue<std::string>(data, "chnannelId");
    content = client->utils->getValue<std::string>(data, "content");
    embeds = client->utils->getValue<vector<EmbedStructure>>(data, "embeds");
    replyMessageIDs = client->utils->getValue<vector<string>>(data, "replyMessageIds");
    isPrivate = client->utils->getValue<bool>(data, "isPrivate");
    isSilent = client->utils->getValue<bool>(data, "isSilent");
    mentions = client->utils->getValue<std::string>(data, "mentions");
    createdAt = client->utils->getValue<std::string>(data, "createdAt");
    createdBy = client->utils->getValue<std::string>(data, "createdBy");
    createdByWebhookID = client->utils->getValue<std::string>(data, "createdByWebhookId");
    updatedAt = client->utils->getValue<std::string>(data, "updatedAt");
}
