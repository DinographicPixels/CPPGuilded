//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#ifndef CPPGUILDED_MESSAGE_HPP
#define CPPGUILDED_MESSAGE_HPP

#include "static.hpp"
#include "REST/Definitions.hpp"

namespace CPPGuilded {
	class Client;
	class Embed;
    class Message {
	 protected:
		CPPGuilded::Client* client;
     public:
        string id;
        string type;
        string guildID;
        string channelID;
        string content;
        vector<Embed> embeds;
        vector<string> replyMessageIDs;
        bool isPrivate;
        bool isSilent;
        string mentions;
        string createdAt;
        string createdBy;
        string createdByWebhookID;
        string updatedAt;
        DLL_EXPORT Message(const json& data, Client* client);
		DLL_EXPORT CPPGuilded::Message create_message(CPPGuilded::MethodOptions::CreateMessage options);
		DLL_EXPORT CPPGuilded::Message edit_message(CPPGuilded::MethodOptions::EditMessage options);
		DLL_EXPORT void delete_message();
    };
}

#endif
