//
// Created by PakkoGraphic on 2/24/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#include "static.hpp"
#include <iostream>

#include "Classes/Base.hpp"
#include "Classes/REST/Definitions.hpp"

#ifndef CPPGUILDED_FORUMTHREAD_HPP
#define CPPGUILDED_FORUMTHREAD_HPP

namespace CPPGuilded
{
	class Client;
	class ForumThread: public Base<int>
	{
	 public:
		std::string guildID;
		std::string channelID;
		std::string title;
		std::string createdAt;
		std::string createdBy;
		std::optional<std::string> updatedAt;
		std::optional<std::string> bumpedAt;
		bool isPinned;
		bool isLocked;
		std::string content;
		std::optional<CPPGuilded::Models::APIMentions> mentions;

		ForumThread(const json& data, Client* client);
	};

} // CPPGuilded

#endif //CPPGUILDED_FORUMTHREAD_HPP
