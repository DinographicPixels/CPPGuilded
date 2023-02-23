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
		CPPGuilded::Message create_message(const std::string& channelID, const MethodOptions::CreateMessage& options);
		CPPGuilded::Message edit_message(const std::string& channelID, const std::string& messageID, const MethodOptions::EditMessage& options);
		void delete_message(const std::string& channelID, const std::string& messageID);
		CPPGuilded::Message get_message(const std::string& channelID, const std::string& messageID);
		std::vector<CPPGuilded::Message> get_messages(const std::string& channelID, const MethodFilters::GetChannelMessages& filter);
		CPPGuilded::Channel create_channel(const MethodOptions::CreateChannel& options);
		CPPGuilded::Channel edit_channel(const std::string& channelID, const MethodOptions::EditChannel& options);
		CPPGuilded::Channel get_channel(const std::string& channelID);
		void delete_channel(const std::string& channelID);
	};
}

#endif
