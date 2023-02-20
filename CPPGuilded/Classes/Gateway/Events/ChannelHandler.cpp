//
// Created by PakkoGraphic on 2/20/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "ChannelHandler.hpp"
#include <iostream>
#include "static.hpp"

#include "library.hpp"
#include "Classes/Channel.hpp"

void CPPGuilded::ChannelHandler::channel_create(const json& data, Client* client)
{
	std::cout << "a channel was created." << std::endl;
	Channel channel = Channel(data.at("channel"), client);
	client->on_channel_create(channel);
}

void CPPGuilded::ChannelHandler::channel_update(const json& data, Client* client)
{
	std::cout << "a channel was updated" << std::endl;
	Channel channel = Channel(data.at("channel"), client);
	client->on_channel_update(channel);
}

void CPPGuilded::ChannelHandler::channel_delete(const json& data, Client* client)
{
	std::cout << "a channel was deleted" << std::endl;
	Channel channel = Channel(data.at("channel"), client);
	client->on_channel_delete(channel);
}