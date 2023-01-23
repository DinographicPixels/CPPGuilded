#pragma once
#include "static.hpp"

namespace CPPGuilded {
	class Client;
    class Message {
    public:
	  struct EmbedStructure {
		  string title;
		  string description;
		  string url = "https://touchguild.com";
		  int color;
		  NLOHMANN_DEFINE_TYPE_INTRUSIVE(EmbedStructure, title, description, url, color);
	  };
        string id;
        string type;
        string serverID;
        string channelID;
        string content;
        vector<EmbedStructure> embeds;
        vector<string> replyMessageIDs;
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
