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
	class ForumThread;
	class Channels {
	 protected:
		CPPGuilded::Client* client;
		std::shared_ptr<CPPGuilded::RequestHandler> manager;
		Utils::Logger log;
	 public:
		Channels(CPPGuilded::Client* client, std::shared_ptr<CPPGuilded::RequestHandler> manager);
		/**
		 * Create a message in a chat channel.
		 * @param channelID ID of the channel to create message in.
		 * @param options Create message options.
		 * @return Message
		 */
		CPPGuilded::Message create_message(const std::string& channelID, const MethodOptions::CreateMessage& options);
		/**
		 * Edit a channel message.
		 * @param channelID ID of the channel containing the message to edit.
		 * @param messageID ID of the message to edit.
		 * @param options Edit options.
		 * @return Message
		 */
		CPPGuilded::Message edit_message(const std::string& channelID, const std::string& messageID, const MethodOptions::EditMessage& options);
		/**
		 * Delete a channel message.
		 * @param channelID ID of the channel containing the message to delete.
		 * @param messageID ID of the message to delete.
		 */
		void delete_message(const std::string& channelID, const std::string& messageID);
		/**
		 * Get a channel message.
		 * @param channelID ID of the channel containing the message to get.
		 * @param messageID ID of the message to get.
		 * @return Message
		 */
		CPPGuilded::Message get_message(const std::string& channelID, const std::string& messageID);
		/**
		 * Get channel messages.
		 * @param channelID The ID of the channel containing messages.
		 * @param filter Filter output.
		 * @return std::vector<CPPGuilded::Message>
		 */
		std::vector<CPPGuilded::Message> get_messages(const std::string& channelID, const MethodFilters::GetChannelMessages& filter);
		/**
		 * Create a channel within a Guild.
		 * @param options Create options.
		 * @return Channel
		 */
		CPPGuilded::Channel create_channel(const MethodOptions::CreateChannel& options);
		/**
		 * Edit a guild channel.
		 * @param channelID ID of the channel to update.
		 * @param options Edit options.
		 * @return Channel
		 */
		CPPGuilded::Channel edit_channel(const std::string& channelID, const MethodOptions::EditChannel& options);
		/**
		 * Get a guild channel.
		 * @param channelID ID of the channel to get.
		 * @return Channel
		 */
		CPPGuilded::Channel get_channel(const std::string& channelID);
		/**
		 * Delete a guild channel.
		 * @param channelID ID of the channel to delete.
		 */
		void delete_channel(const std::string& channelID);
		/**
		 * Create a new thread inside a Forum channel.
		 * @param channelID ID of a Forum channel.
		 * @param title Title of the thread.
		 * @param content Content of the thread.
		 * @return ForumThread
		 */
		CPPGuilded::ForumThread create_forum_thread(const std::string& channelID, const std::string& title, const std::string& content);
		/**
		 * Edit an existing thread inside a Forum channel.
		 * @param channelID ID of a Forum channel.
		 * @param threadID ID of the thread to edit.
		 * @param title New title (optional)
		 * @param content New content (optional)
		 * @return ForumThread
		 */
		CPPGuilded::ForumThread edit_forum_thread(const std::string& channelID, const std::string& threadID,
			const std::optional<std::string>& title, const std::optional<std::string>& content);

		void delete_forum_thread(const std::string& channelID, const std::string& threadID);
	};
}

#endif
