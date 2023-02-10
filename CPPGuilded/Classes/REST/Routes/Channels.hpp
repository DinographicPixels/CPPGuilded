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

		Channels(CPPGuilded::Client* client, std::shared_ptr<CPPGuilded::RequestHandler> manager);
		CPPGuilded::Message create_message(std::string channelID, CreateMessageOptions options);
		CPPGuilded::Message edit_message(std::string channelID, std::string messageID, EditMessageOptions options);
		void delete_message(std::string channelID, std::string messageID);
	};
}

#endif
