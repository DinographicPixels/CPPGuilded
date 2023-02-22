//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#ifndef CPPGUILDED_MESSAGE_HPP
#define CPPGUILDED_MESSAGE_HPP

#include "static.hpp"
#include "Classes/Base.hpp"
#include "REST/Definitions.hpp"

namespace CPPGuilded {
	class Client;
	class Embed;
    class Message: public Base<std::string> {
	 protected:
		CPPGuilded::Client* client;
     public:
        string type;
        std::optional<string> guildID;
        string channelID;
        std::optional<string> content;
        vector<Embed> embeds;
        vector<string> replyMessageIDs;
        std::optional<bool> isPrivate;
        std::optional<bool> isSilent;
        std::optional<string> mentions;
        string createdAt;
        string createdBy;
        std::optional<string> createdByWebhookID;
        std::optional<string> updatedAt;
        DLL_EXPORT Message(const json& data, Client* client);
		DLL_EXPORT CPPGuilded::Message create_message(CPPGuilded::MethodOptions::CreateMessage options);
		DLL_EXPORT CPPGuilded::Message edit_message(CPPGuilded::MethodOptions::EditMessage options);
		DLL_EXPORT void delete_message();
    };
}

#endif
