#include "Channel.hpp"
#include "static.hpp"
#include <iostream>

#include "library.hpp"

using namespace std;

CPPGuilded::Channel::Channel(const json& data, Client* client) {
    id = data.at("id").get<string>();
    type = data.at("type").get<string>();
    name = data.at("name").get<string>();
    topic = data.at("topic").get<string>();
    createdAt = data.at("createdAt").get<string>();
    createdBy = data.at("createdBy").get<string>();
    serverID = data.at("serverId").get<string>();
    groupID = data.at("groupId").get<string>();
};