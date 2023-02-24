//
// Created by PakkoGraphic on 2/24/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#include "static.hpp"
#include <iostream>

#ifndef CPPGUILDED_FORUMTHREADHANDLER_HPP
#define CPPGUILDED_FORUMTHREADHANDLER_HPP

namespace CPPGuilded
{
	class Client;
	class ForumThreadHandler
	{
	 public:
		void forum_thread_create(const json& data, Client* client);
		void forum_thread_update(const json& data, Client* client);
		void forum_thread_delete(const json& data, Client* client);
	};
} // CPPGuilded

#endif //CPPGUILDED_FORUMTHREADHANDLER_HPP
