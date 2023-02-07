#pragma once
#include <iostream>
#include "static.hpp"
#include "Classes/Gateway/WSManager.hpp"
#include "Classes/Gateway/Events/MessageHandler.hpp"
#include "library.hpp"

namespace CPPGuilded {
	class GatewayHandler: public WSManager {
	  protected:
		std::unique_ptr<CPPGuilded::MessageHandler> message_handler;
	  public:
		Client* client;
		DLL_EXPORT GatewayHandler(Client* client);
		DLL_EXPORT ~GatewayHandler(){};
		DLL_EXPORT shared_future<void> ON_GATEWAY_PARSED_PACKET(const std::string& name, const json& data) override;
		DLL_EXPORT shared_future<void> connect() override;
	  private:
	};
}

