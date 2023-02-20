//
// Created by PakkoGraphic on 2/20/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once
#include "static.hpp"
#include <iostream>

#ifndef CPPGUILDED_CHANNELHANDLER_HPP
#define CPPGUILDED_CHANNELHANDLER_HPP

namespace CPPGuilded
{
	class Client;
	class ChannelHandler
	{
	 public:
		void channel_create(const json& data, Client* client);
		void channel_update(const json& data, Client* client);
		void channel_delete(const json& data, Client* client);
	};

} // CPPGuilded

#endif //CPPGUILDED_CHANNELHANDLER_HPP
