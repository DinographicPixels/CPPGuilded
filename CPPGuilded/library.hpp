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
#include "Classes/RequestHandler.hpp"

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
        DLL_EXPORT Client(string token);
        std::string token;
        std::unique_ptr<CPPGuilded::Utils> utils;
		CPPGuilded::Utils::Logger log;
		std::unique_ptr<CPPGuilded::RequestHandler> rest;
		std::shared_ptr<CPPGuilded::GatewayHandler> gatewayHandler;
        bool hello(bool sus);
		Message create_message(std::string channelID, CreateMessageOptions options);
		Message edit_message(std::string channelID, std::string messageID, EditMessageOptions options);
		void delete_message(std::string channelID, std::string messageID);
		Member get_member(std::string guildID, std::string memberID);
		Message::Embed test (Message::Embed structure);
		DLL_EXPORT void connect();
		DLL_EXPORT virtual void on_message_create(CPPGuilded::Message message);
		DLL_EXPORT virtual void on_message_update(CPPGuilded::Message message);
		DLL_EXPORT virtual void on_message_delete(CPPGuilded::Message message);
    };
}

#endif