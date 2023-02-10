#pragma once

#ifndef CPPGUILDED_REQUESTHANDLER_HPP
#define CPPGUILDED_REQUESTHANDLER_HPP

#include "static.hpp"


namespace CPPGuilded {
	class Client;
	class RequestHandler {
	  public:
		struct GuildedHTTPResponse {
			unsigned int statusCode;
			std::map<std::string, std::string> headers;
			std::string body;
		};
		GuildedHTTPResponse request(const string method, const string target, const string& data = "");
		DLL_EXPORT RequestHandler(Client* client);
		Client* client;
	};
}

#endif