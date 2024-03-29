//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#ifndef CPPGUILDED_REQUESTHANDLER_HPP
#define CPPGUILDED_REQUESTHANDLER_HPP

#include "static.hpp"
#include "Utils.hpp"

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
		Utils::Logger log;
		DLL_EXPORT RequestHandler(Client* client);
		Client* client;
	};
}

#endif