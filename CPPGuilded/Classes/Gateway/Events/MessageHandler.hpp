//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once
#include <iostream>
#include "static.hpp"

namespace CPPGuilded {
	class Client;
	class MessageHandler {
	  public:
		DLL_EXPORT void messageCreate(const json& data, Client* client);
		DLL_EXPORT void messageUpdate(const json& data, Client* client);
		DLL_EXPORT void messageDelete(const json& data, Client* client);
	};
}