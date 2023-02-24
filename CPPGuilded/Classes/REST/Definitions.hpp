//
// Created by PakkoGraphic on 2/20/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#ifndef CPPGUILDED_DEFINITIONS_HPP
#define CPPGUILDED_DEFINITIONS_HPP

#include <iostream>
#include "static.hpp"
#include "Classes/Embed.hpp"
#include "Classes/Utils.hpp"
#include "Classes/Exceptions.hpp"

namespace CPPGuilded {
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
	class Models {
	 private:
	 public:
		struct APIMentionsObjectStringID {
			std::string id;
		};
		struct APIMentionsObjectIntegerID {
			int id;
		};
		class APIMentions {
		 private:
			Utils utils;
		 public:
			vector<APIMentionsObjectStringID> users;
			vector<APIMentionsObjectStringID> channels;
			vector<APIMentionsObjectIntegerID> roles;
			bool everyone;
			bool here;

			APIMentions(const json& mentions){
				if (utils.has_value(mentions, "users")){
					for (json userObject : mentions.at("users")){
						APIMentionsObjectStringID object;
						userObject.at("id").get_to(object.id);
						users.push_back(object);
					}
				}

				if (utils.has_value(mentions, "channels")){
					for (json channelObject : mentions.at("channels")){
						APIMentionsObjectStringID object;
						channelObject.at("id").get_to(object.id);
						channels.push_back(object);
					}
				}

				if (utils.has_value(mentions, "roles")){
					for (json roleObject : mentions.at("roles")){
						APIMentionsObjectIntegerID object;
						roleObject.at("id").get_to(object.id);
						roles.push_back(object);
					}
				}

				this->everyone = utils.get_or_else<bool>(mentions, "everyone", false);
				this->here = utils.get_or_else<bool>(mentions, "here", false);
			};
			// NLOHMANN_DEFINE_TYPE_INTRUSIVE(APIMentions, everyone, here);
		};

		class MemberUpdateInfo {
		 private:
			Utils utils;
		 public:
			std::string memberID;
			std::string guildID;
			std::optional<std::string> nickname;
			MemberUpdateInfo(const json& data) {
				if (!utils.has_value(data, "userInfo")) throw CPPGuilded::GuildedException("Couldn't get user information data from payload.");
				memberID = utils.get_or_else<std::string>(data.at("userInfo"), "id", "");
				guildID = utils.get_or_else<std::string>(data, "serverId", "");
				nickname = utils.get_optional<std::string>(data.at("userInfo"), "nickname");
			};
		};

		class MemberRemoveInfo {
		 private:
			Utils utils;
		 public:
			std::string guildID;
			std::string memberID;
			std::optional<bool> isKicked;
			std::optional<bool> isBanned;
			MemberRemoveInfo(const json& data){
				guildID = utils.get_or_else<std::string>(data, "serverId", "");
				memberID = utils.get_or_else<std::string>(data, "memberId", "");
				isKicked = utils.get_optional<bool>(data, "isKick");
				isBanned = utils.get_optional<bool>(data, "isBan");
			};
		};
	};
}

#endif //CPPGUILDED_DEFINITIONS_HPP
