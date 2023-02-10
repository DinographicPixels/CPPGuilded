#include "User.hpp"
#include "static.hpp"
#include <iostream>

CPPGuilded::User::User(const json& data, Client* client) {
	this->id = client->utils->get_value<std::string>(data, "id");
	this->type = client->utils->get_value<std::string>(data, "type");
	this->username = client->utils->get_value<std::string>(data, "name");
	this->avatarURL = client->utils->get_value<std::string>(data, "avatar");
}
