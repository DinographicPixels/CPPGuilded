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
		struct POSTChannelMessageBODY {
			bool isPrivate = false;
			bool isSilent = false;
			string replyMessageIds = "";
			string content = "";
			string embeds = "";
			NLOHMANN_DEFINE_TYPE_INTRUSIVE(POSTChannelMessageBODY, isPrivate, isSilent, replyMessageIds, content, embeds)
		};
    public:
        DLL_EXPORT Client(string TOKEN);
        std::string token;
        CPPGuilded::Utils* utils;
		RequestHandler* rest;
        bool hello(bool sus);
		Message* createMessage(std::string channelID, POSTChannelMessageBODY options);
    };
}

// #endif //CPPGUILDED_LIBRARY_H
