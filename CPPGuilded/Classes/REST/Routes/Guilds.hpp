#include <iostream>

#ifndef CPPGUILDED_GUILDS_HPP
#define CPPGUILDED_GUILDS_HPP

#include "static.hpp"

namespace CPPGuilded {
	class Client;
	class RequestHandler;
	class Member;
	class Guilds {
	 protected:
		CPPGuilded::Client* client;
		std::shared_ptr<CPPGuilded::RequestHandler> manager;
	 public:
		Guilds(CPPGuilded::Client* client, std::shared_ptr<CPPGuilded::RequestHandler> manager);
		CPPGuilded::Member get_member(std::string guildID, std::string memberID);
	};
}

#endif //CPPGUILDED_GUILDS_HPP
