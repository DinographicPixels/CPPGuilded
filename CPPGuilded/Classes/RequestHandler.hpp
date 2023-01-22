#pragma once
#include "static.hpp"


namespace CPPGuilded {
	class Client;
	class RequestHandler {
	  public:
		struct GuildedHTTPResponse {
			unsigned int status_code;
			std::map<std::string, std::string> headers;
			std::string body;
		};
		GuildedHTTPResponse request(const string method, const string target, const string& data = "");
		DLL_EXPORT RequestHandler(Client* client);
		Client* client;
	};
}
