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
		std::unique_ptr<CPPGuilded::RESTManager> rest;
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


		// EVENTS
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

		// METHODS
		/**
		 * Create a message in a chat channel.
		 * @param channelID ID of the channel to create message in.
		 * @param options Create message options.
		 * @return Message
		 */
		DLL_EXPORT CPPGuilded::Message create_message(std::string channelID, CPPGuilded::MethodOptions::CreateMessage options);
		/**
		 * Edit a channel message.
		 * @param channelID ID of the channel containing the message to edit.
		 * @param messageID ID of the message to edit.
		 * @param options Edit options.
		 * @return Message
		 */
		DLL_EXPORT CPPGuilded::Message edit_message(std::string channelID, std::string messageID, CPPGuilded::MethodOptions::EditMessage options);
		/**
		 * Delete a channel message.
		 * @param channelID ID of the channel containing the message to delete.
		 * @param messageID ID of the message to delete.
		 */
		DLL_EXPORT void delete_message(std::string channelID, std::string messageID);
		/**
		 * Get a guild member.
		 * @param guildID ID of the guild the member is in.
		 * @param memberID ID of the member to get.
		 * @return Member
		 */
		DLL_EXPORT CPPGuilded::Member get_member(std::string guildID, std::string memberID);
		/**
		 * Get a channel message.
		 * @param channelID ID of the channel containing the message to get.
		 * @param messageID ID of the message to get.
		 * @return Message
		 */
		DLL_EXPORT CPPGuilded::Message get_message(std::string channelID, std::string messageID);
		/**
		 * Get channel messages.
		 * @param channelID The ID of the channel containing messages.
		 * @param filter Filter output.
		 * @return std::vector<CPPGuilded::Message>
		 */
		DLL_EXPORT std::vector<CPPGuilded::Message> get_messages(std::string channelID, CPPGuilded::MethodFilters::GetChannelMessages filter);
		/**
		 * Get a user.
		 * @param userID The ID of a Guilded user.
		 * @return User
		 */
		DLL_EXPORT CPPGuilded::User get_user(const std::string& userID);
    };
}

#endif