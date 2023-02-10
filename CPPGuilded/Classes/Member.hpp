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
		std::string nickname;
		std::string joinedAt;
		bool isOwner = false;
		Member(const json& data, Client* client);
	};
}


#endif //CPPGUILDED_MEMBER_HPP
