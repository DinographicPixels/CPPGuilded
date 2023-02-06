#include "GatewayHandler.hpp"
#include "static.hpp"

#include <iostream>

CPPGuilded::GatewayHandler::GatewayHandler(std::string& token): CPPGuilded::WSManager(token) {

}

void CPPGuilded::GatewayHandler::ON_GATEWAY_PARSED_PACKET(std::string& name, json& data) {
	std::cout << "event name: " << name << std::endl;
	std::cout << "data: " << data << std::endl;
}
