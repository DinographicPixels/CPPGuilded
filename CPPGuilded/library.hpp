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
        DLL_EXPORT Client(string token);
        std::string token;
        std::unique_ptr<CPPGuilded::Utils> utils;
		CPPGuilded::Utils::Logger log;
		std::unique_ptr<CPPGuilded::RESTManager> rest;
		std::shared_ptr<CPPGuilded::GatewayHandler> gatewayHandler;
        bool hello(bool sus);
		Message::Embed test (Message::Embed structure);
		DLL_EXPORT void connect();
		// EVENTS
		DLL_EXPORT virtual void on_message_create(CPPGuilded::Message message);
		DLL_EXPORT virtual void on_message_update(CPPGuilded::Message message);
		DLL_EXPORT virtual void on_message_delete(CPPGuilded::Message message);
		// METHODS
		DLL_EXPORT CPPGuilded::Message create_message(std::string channelID, CPPGuilded::Channels::CreateMessageOptions options);
		DLL_EXPORT CPPGuilded::Message edit_message(std::string channelID, std::string messageID, CPPGuilded::Channels::EditMessageOptions options);
		DLL_EXPORT void delete_message(std::string channelID, std::string messageID);
		DLL_EXPORT CPPGuilded::Member get_member(std::string guildID, std::string memberID);
		DLL_EXPORT CPPGuilded::Message get_message(std::string channelID, std::string messageID);
		DLL_EXPORT std::vector<CPPGuilded::Message> get_messages(std::string channelID, CPPGuilded::Channels::GetChannelMessagesFilter filter);
    };
}

#endif