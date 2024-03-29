//
// Created by PakkoGraphic on 2/10/2023.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "RESTManager.hpp"

#include <iostream>
#include "static.hpp"

#include "Classes/RequestHandler.hpp"

CPPGuilded::RESTManager::RESTManager(CPPGuilded::Client* client): client(client), channels(Channels(client, manager)),
guilds(Guilds(client, manager)), misc(Misc(client, manager)) {}

