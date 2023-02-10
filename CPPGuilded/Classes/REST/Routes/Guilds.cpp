#include "Guilds.hpp"
#include <iostream>
#include "static.hpp"

#include "Classes/Member.hpp"
#include "Classes/RequestHandler.hpp"

CPPGuilded::Guilds::Guilds(CPPGuilded::Client* client, std::shared_ptr<CPPGuilded::RequestHandler> manager): client(client), manager(manager) {};

CPPGuilded::Member CPPGuilded::Guilds::get_member(std::string guildID, std::string memberID) {
	RequestHandler::GuildedHTTPResponse req = manager->request("GET", "/servers/" + guildID + "/members/" + memberID);
	json res = json::parse(req.body).at("member");
	return Member(res, client);
}
