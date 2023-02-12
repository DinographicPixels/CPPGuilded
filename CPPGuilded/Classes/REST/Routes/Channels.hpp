//
// Created by PakkoGraphic on 2/10/2023.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include <iostream>

#ifndef CPPGUILDED_CHANNELS_HPP
#define CPPGUILDED_CHANNELS_HPP

#include "static.hpp"

#include "Classes/Message.hpp"

namespace CPPGuilded {
	class Client;
	class RequestHandler;
	class Channels {
	 protected:
		CPPGuilded::Client* client;
		std::shared_ptr<CPPGuilded::RequestHandler> manager;
	 public:
		struct CreateMessageOptions {
			string content;
			vector<string> replyMessageIds;
			bool isPrivate = false;
			bool isSilent = false;
			vector<Message::Embed> embeds;
			NLOHMANN_DEFINE_TYPE_INTRUSIVE(CreateMessageOptions, content, replyMessageIds, isPrivate, isSilent);
		};
		struct EditMessageOptions {
			std::string content;
			vector<Message::Embed> embeds;
			NLOHMANN_DEFINE_TYPE_INTRUSIVE(EditMessageOptions, content);
		};
		struct GetChannelMessagesFilter {
			std::string before;
			std::string after;
			int limit;
			bool includePrivate;
			NLOHMANN_DEFINE_TYPE_INTRUSIVE(GetChannelMessagesFilter, before, after, limit, includePrivate);
		};

		Channels(CPPGuilded::Client* client, std::shared_ptr<CPPGuilded::RequestHandler> manager);
		CPPGuilded::Message create_message(std::string channelID, CreateMessageOptions options);
		CPPGuilded::Message edit_message(std::string channelID, std::string messageID, EditMessageOptions options);
		void delete_message(std::string channelID, std::string messageID);
		CPPGuilded::Message get_message(std::string channelID, std::string messageID);
		std::vector<CPPGuilded::Message> get_messages(std::string channelID, GetChannelMessagesFilter filter);
	};
}

#endif
