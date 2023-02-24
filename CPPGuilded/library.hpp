//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once
#include <iostream>
#include <map>

#ifndef CPPGUILDED_LIBRARY_HPP
#define CPPGUILDED_LIBRARY_HPP

#include "static.hpp"
// #include "Classes/Utils.hpp"
// #ifndef cppguilded
// #define cppguilded

#include <boost/beast/http.hpp>

#include "Classes/Utils.hpp"
// #include "Classes/Message.hpp"
#include "Classes/REST/RESTManager.hpp"
#include "Classes/REST/Routes/Channels.hpp"

using namespace boost;

namespace http = boost::beast::http;

namespace CPPGuilded {
	class Member;
	class Message;
	class GatewayHandler;
	class ForumThread;
	// struct GuildedHTTPResponse;
    class Client {
    private:
    public:
		/**
		 * Client constructor, requires token.
		 * @param token The bot TOKEN that is provided by Guilded.
		 */
        DLL_EXPORT Client(string token);
	    /**
	     * The bot token provided when initializing the constructor.
	     */
        std::string token;
		/**
		 * CPPGuilded internal utilities.
		 */
        std::unique_ptr<CPPGuilded::Utils> utils;
		/**
		 * CPPGuilded internal logger.
		 */
		CPPGuilded::Utils::Logger log;
		/**
		 * The RESTManager class, where you can use REST methods.\n (rest#guilds, rest#channels, rest#misc)
		 */
		CPPGuilded::RESTManager rest;
		/**
		 * GatewayHandler is used to let you stay in touch with the Guilded API.\n
		 * Please do not touch.
		 */
		std::shared_ptr<CPPGuilded::GatewayHandler> gatewayHandler;
        bool hello(bool sus);
		Embed test (Embed structure);
		/**
		 * This method is used to connect your bot to the Guilded API.
		 */
		DLL_EXPORT void connect();


		/** EVENTS */
		/**
		 * Event fired when a channel message is created.
		 * @param message The created message.
		 */
		DLL_EXPORT virtual void on_message_create(CPPGuilded::Message message);
		/**
		 * Event fired when a channel message is edited.
		 * @param message The new version of the edited message.
		 */
		DLL_EXPORT virtual void on_message_update(CPPGuilded::Message message);
		/**
		 * Event fired when a channel message is deleted.
		 * @param message Deleted message.
		 */
		DLL_EXPORT virtual void on_message_delete(CPPGuilded::Message message);
		/**
		 * Event fired when a channel is created.
		 * @param channel Created channel.
		 */
		DLL_EXPORT virtual void on_channel_create(CPPGuilded::Channel channel);
		/**
		 * Event fired when a channel is edited.
		 * @param channel Updated channel.
		 */
		DLL_EXPORT virtual void on_channel_update(CPPGuilded::Channel channel);
		/**
		 * Event fired when a channel is deleted.
		 * @param channel Deleted channel.
		 */
		DLL_EXPORT virtual void on_channel_delete(CPPGuilded::Channel channel);
		/**
		 * Event fired when a member has updated his guild profile.
		 * @param memberUpdateInfo Information related the member's updated profile.
		 */
		DLL_EXPORT virtual void on_guild_member_update(CPPGuilded::Models::MemberUpdateInfo memberUpdateInfo);
		/**
		 * Event fired when a member left from a guild.
		 * @param memberRemoveInfo Information about the removal of a member.
		 */
		DLL_EXPORT virtual void on_guild_member_remove(CPPGuilded::Models::MemberRemoveInfo memberRemoveInfo);
		/**
		 * Event fired when a member gets banned.
		 * @param bannedMember Information about the ban.
		 */
		DLL_EXPORT virtual void on_guild_member_ban(CPPGuilded::BannedMember bannedMember);
		/**
		 * Event fired when a member is unbanned.
		 * @param bannedMember Information about the removed ban.
		 */
		DLL_EXPORT virtual void on_guild_member_unban(CPPGuilded::BannedMember bannedMember);
		/**
		 * Event fired when a forum thread is created.
		 * @param forumThread Created forum thread.
		 */
		DLL_EXPORT virtual void on_forum_thread_create(CPPGuilded::ForumThread forumThread);
		/**
		 * Event fired when a forum thread is updated.
		 * @param forumThread Updated forum thread.
		 */
		DLL_EXPORT virtual void on_forum_thread_update(CPPGuilded::ForumThread forumThread);
		/**
		 * Event fired when a forum thread is deleted.
		 * @param forumThread Deleted forum thread.
		 */
		DLL_EXPORT virtual void on_forum_thread_delete(CPPGuilded::ForumThread forumThread);

    };
}

#endif