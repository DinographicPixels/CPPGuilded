//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#ifndef CPPGUILDED_CHANNEL_HPP
#define CPPGUILDED_CHANNEL_HPP

#include <iostream>
#include "static.hpp"
#include "Classes/Base.hpp"
#include "Classes/REST/Definitions.hpp"
using namespace std;

namespace CPPGuilded {
	class Client;
    class Channel: public Base<std::string> {
	 protected:
		CPPGuilded::Client* client;
     public:
		std::string type;
		std::string name;
		std::optional<std::string> topic;
		std::string createdAt;
		std::string createdBy;
		std::optional<std::string> updatedAt;
		std::string guildID;
		std::optional<std::string> parentID;
		std::optional<std::string> categoryID;
		std::string groupID;
		std::optional<bool> isPublic;
		std::optional<std::string> archivedBy;
		std::optional<std::string> archivedAt;
        DLL_EXPORT Channel(const json& data, Client* client);
		/**
		 * Edit this channel.
		 * @param options Edit options.
		 * @return Channel
		 */
		DLL_EXPORT CPPGuilded::Channel edit(CPPGuilded::MethodOptions::EditChannel options);
		/**
		 * Delete this channel.
		 */
		DLL_EXPORT void delete_c();
    };

    void sus();
}

#endif
