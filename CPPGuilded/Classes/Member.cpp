#include "Member.hpp"
#include <iostream>
#include "static.hpp"

CPPGuilded::Member::Member(const json& data, Client* client): User(data.at("user"), client) {
	this->roleIDs = client->utils->get_value<std::vector<int>>(data, "roleIds");
	this->nickname = client->utils->get_value<std::string>(data, "nickname");
	this->joinedAt = client->utils->get_value<std::string>(data, "joinedAt");
	this->isOwner = client->utils->get_value<bool>(data, "isOwner");
}
