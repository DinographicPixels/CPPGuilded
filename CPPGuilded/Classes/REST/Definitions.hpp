//
// Created by PakkoGraphic on 2/20/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#ifndef CPPGUILDED_DEFINITIONS_HPP
#define CPPGUILDED_DEFINITIONS_HPP

#include <iostream>
#include "static.hpp"

namespace CPPGuilded {
	class Embed;
	class MethodOptions {
	 public:
		struct CreateMessage {
			string content;
			vector<string> replyMessageIds;
			bool isPrivate = false;
			bool isSilent = false;
			vector<Embed> embeds;
			NLOHMANN_DEFINE_TYPE_INTRUSIVE(CreateMessage, content, replyMessageIds, isPrivate, isSilent);
		};
		struct EditMessage {
			std::string content;
			vector<Embed> embeds;
			NLOHMANN_DEFINE_TYPE_INTRUSIVE(EditMessage, content);
		};
		struct CreateChannel {
			std::string name;
			std::optional<std::string> topic;
			std::optional<bool> isPublic;
			std::string type;
			std::optional<std::string> serverId;
			std::optional<std::string> groupId;
			std::optional<int> categoryId;
			// NLOHMANN_DEFINE_TYPE_INTRUSIVE(CreateChannel, name, type);
		};
		struct EditChannel {
			std::optional<std::string> name;
			std::optional<std::string> topic;
			std::optional<bool> isPublic;
			// NLOHMANN_DEFINE_TYPE_INTRUSIVE(EditChannel, name, topic, isPublic);
		};
	};
	class MethodFilters {
	 public:
		struct GetChannelMessages {
			std::string before;
			std::string after;
			int limit;
			bool includePrivate;
			NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetChannelMessages, before, after, limit, includePrivate);
		};
	};
}

#endif //CPPGUILDED_DEFINITIONS_HPP
