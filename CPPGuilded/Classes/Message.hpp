#pragma once
#include "library.hpp"

namespace CPPGuilded {
    class Message {
    public:
        string id;
        string type;
        string serverID;
        string channelID;
        string content;
        string embeds;
        string replyMessageIDs;
        bool isPrivate;
        bool isSilent;
        string mentions;
        string createdAt;
        string createdBy;
        string createdByWebhookID;
        string updatedAt;
        DLL_EXPORT Message(json& data, Client* client);
    };
}
