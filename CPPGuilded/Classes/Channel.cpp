//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "Channel.hpp"
#include "static.hpp"
#include <iostream>

#include "library.hpp"

using namespace std;

CPPGuilded::Channel::Channel(const json& data, Client* client) {
    id = client->utils->get_value<std::string>(data, "id");
    type = client->utils->get_value<std::string>(data, "type");
    name = client->utils->get_value<std::string>(data, "name");
    topic = client->utils->get_value<std::string>(data, "topic");
    createdAt = client->utils->get_value<std::string>(data, "createdAt");
    createdBy = client->utils->get_value<std::string>(data, "createdBy");
    serverID = client->utils->get_value<std::string>(data, "serverId");
    groupID = client->utils->get_value<std::string>(data, "groupId");
};