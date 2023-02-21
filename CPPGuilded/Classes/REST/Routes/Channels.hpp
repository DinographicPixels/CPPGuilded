//
// Created by PakkoGraphic on 2/10/2023.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include <iostream>

#ifndef CPPGUILDED_CHANNELS_HPP
#define CPPGUILDED_CHANNELS_HPP

#include "static.hpp"

#include "Classes/Message.hpp"
#include "Classes/Channel.hpp"
#include "Classes/Utils.hpp"

namespace CPPGuilded {
	class Client;
	class RequestHandler;
	class Channels {
	 protected:
		CPPGuilded::Client* client;
		std::shared_ptr<CPPGuilded::RequestHandler> manager;
		Utils::Logger log;
	 public:
		Channels(CPPGuilded::Client* client, std::shared_ptr<CPPGuilded::RequestHandler> manager);
		CPPGuilded::Message create_message(std::string channelID, MethodOptions::CreateMessage options);
		CPPGuilded::Message edit_message(std::string channelID, std::string messageID, MethodOptions::EditMessage options);
		void delete_message(std::string channelID, std::string messageID);
		CPPGuilded::Message get_message(std::string channelID, std::string messageID);
		std::vector<CPPGuilded::Message> get_messages(std::string channelID, MethodFilters::GetChannelMessages filter);
		CPPGuilded::Channel create_channel(MethodOptions::CreateChannel options);
		CPPGuilded::Channel edit_channel(std::string channelID, MethodOptions::EditChannel options);
		void delete_channel(std::string channelID);
	};
}

#endif
