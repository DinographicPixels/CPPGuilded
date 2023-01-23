#pragma once
#include <iostream>
#include <map>

#include "static.hpp"
// #include "Classes/Utils.hpp"
// #ifndef cppguilded
// #define cppguilded

#include <boost/beast/http.hpp>

#include "Classes/Utils.hpp"
// #include "Classes/Message.hpp"

using namespace boost;

namespace http = boost::beast::http;

namespace CPPGuilded {
	class Message;
	class RequestHandler;
	// struct GuildedHTTPResponse;
    class Client {
    private:
    public:
	  struct CreateMessageOptions {
		  string content;
		  vector<string> replyMessageIds;
		  bool isPrivate = false;
		  bool isSilent = false;
		  vector<Message::Embed*> embeds;
		  NLOHMANN_DEFINE_TYPE_INTRUSIVE(CreateMessageOptions, content, replyMessageIds, isPrivate, isSilent);
	  };
        DLL_EXPORT Client(string TOKEN);
        std::string token;
        CPPGuilded::Utils* utils;
		RequestHandler* rest;
        bool hello(bool sus);
		Message* createMessage(std::string channelID, CreateMessageOptions options);
		Message::Embed test (Message::Embed structure);
    };
}

// #endif //CPPGUILDED_LIBRARY_H
