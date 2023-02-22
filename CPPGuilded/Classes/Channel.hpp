//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#ifndef CPPGUILDED_CHANNEL_HPP
#define CPPGUILDED_CHANNEL_HPP

#include <iostream>
#include "static.hpp"
#include "Classes/REST/Definitions.hpp"
using namespace std;

namespace CPPGuilded {
	class Client;
    class Channel {
	 protected:
		CPPGuilded::Client* client;
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
		/**
		 * Edit this channel.
		 * @param options Edit options.
		 * @return Channel
		 */
		DLL_EXPORT CPPGuilded::Channel edit(CPPGuilded::MethodOptions::EditChannel options);
		/**
		 * Delete this channel.
		 */
		DLL_EXPORT void delete_c();
    };

    void sus();
}

#endif
