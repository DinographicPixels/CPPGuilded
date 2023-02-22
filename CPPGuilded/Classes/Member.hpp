//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#ifndef CPPGUILDED_MEMBER_HPP
#define CPPGUILDED_MEMBER_HPP

#include <iostream>

#include "static.hpp"
#include "User.hpp"

namespace CPPGuilded {
	class Member: public User {
	 public:
		std::vector<int> roleIDs;
		std::optional<std::string> nickname;
		std::string joinedAt;
		std::optional<bool> isOwner = false;
		Member(const json& data, Client* client);
	};
}


#endif //CPPGUILDED_MEMBER_HPP
