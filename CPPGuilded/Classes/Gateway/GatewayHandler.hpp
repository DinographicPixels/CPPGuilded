//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once
#include <iostream>
#include "static.hpp"
#include "Classes/Gateway/WSManager.hpp"
#include "Classes/Gateway/Events/MessageHandler.hpp"
#include "Classes/Gateway/Events/ChannelHandler.hpp"
#include "Classes/Gateway/Events/GuildHandler.hpp"
#include "Classes/Gateway/Events/ForumThreadHandler.hpp"
#include "library.hpp"

namespace CPPGuilded {
	class GatewayHandler: public WSManager {
	  protected:
		std::unique_ptr<CPPGuilded::MessageHandler> messageHandler;
		std::unique_ptr<CPPGuilded::ChannelHandler> channelHandler;
		std::unique_ptr<CPPGuilded::GuildHandler> guildHandler;
		std::unique_ptr<CPPGuilded::ForumThreadHandler> forumThreadHandler;
	  public:
		Client* client;
		DLL_EXPORT GatewayHandler(Client* client);
		DLL_EXPORT ~GatewayHandler(){};
		DLL_EXPORT shared_future<void> ON_GATEWAY_PARSED_PACKET(const std::string& name, const json& data) override;
		DLL_EXPORT shared_future<void> connect() override;
	  private:
	};
}

