//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#ifndef CPPGUILDED_CHANNEL_HPP
#define CPPGUILDED_CHANNEL_HPP

#include <iostream>
#include "static.hpp"
using namespace std;

namespace CPPGuilded {
	class Client;
    class Channel {
    public:
        string id;
        string type;
        string name;
        string topic;
        string createdAt;
        string createdBy;
        string serverID;
        string groupID;
        DLL_EXPORT Channel(const json& data, Client* client);
    };

    void sus();
}

#endif
