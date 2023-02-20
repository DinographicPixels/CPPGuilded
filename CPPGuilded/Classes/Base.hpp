//
// Created by PakkoGraphic on 2/20/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#include <iostream>
#include "static.hpp"

#ifndef CPPGUILDED_BASE_HPP
#define CPPGUILDED_BASE_HPP

namespace CPPGuilded {
	template<typename T = std::string>
	class Base {
	 public:
		T id;
		Base(T id): id(id) {};
	};
}

#endif //CPPGUILDED_BASE_HPP
