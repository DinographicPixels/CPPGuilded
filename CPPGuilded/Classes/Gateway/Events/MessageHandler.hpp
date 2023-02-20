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
		DLL_EXPORT void message_create(const json& data, Client* client);
		DLL_EXPORT void message_update(const json& data, Client* client);
		DLL_EXPORT void message_delete(const json& data, Client* client);
	};
}