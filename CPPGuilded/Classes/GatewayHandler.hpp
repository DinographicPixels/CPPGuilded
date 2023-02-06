#pragma once
#include <iostream>
#include "static.hpp"
#include "WSManager.hpp"

namespace CPPGuilded {
	class GatewayHandler: public CPPGuilded::WSManager {
	  protected:
	  public:
		DLL_EXPORT void ON_GATEWAY_PARSED_PACKET(std::string& name, json& data) override;
		DLL_EXPORT GatewayHandler(std::string& token);
		DLL_EXPORT ~GatewayHandler(){};
	  private:
	};
}

