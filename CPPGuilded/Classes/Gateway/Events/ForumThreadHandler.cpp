//
// Created by PakkoGraphic on 2/24/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "ForumThreadHandler.hpp"
#include "static.hpp"
#include <iostream>

#include "Classes/ForumThread.hpp"
#include "library.hpp"

void CPPGuilded::ForumThreadHandler::forum_thread_create(const json& data, Client* client)
{
	std::cout << "forum_thread_create event fired." << std::endl;
	CPPGuilded::ForumThread forumThread = ForumThread(data.at("forumTopic"), client);
	client->on_forum_thread_create(forumThread);
}

void CPPGuilded::ForumThreadHandler::forum_thread_update(const json& data, Client* client)
{
	std::cout << "forum_thread_update event fired." << std::endl;
	CPPGuilded::ForumThread forumThread = ForumThread(data.at("forumTopic"), client);
	client->on_forum_thread_update(forumThread);
}

void CPPGuilded::ForumThreadHandler::forum_thread_delete(const json& data, Client* client)
{
	std::cout << "forum_thread_delete event fired." << std::endl;
	CPPGuilded::ForumThread forumThread = ForumThread(data.at("forumTopic"), client);
	client->on_forum_thread_delete(forumThread);
}