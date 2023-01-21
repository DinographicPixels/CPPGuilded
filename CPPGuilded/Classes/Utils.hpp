#pragma once
#include "static.hpp"

namespace CPPGuilded {
	class Utils {
	  public:
		DLL_EXPORT Utils() {};
		template<typename T> T getValue(const json& data, std::string name) {
			return data.value(name, "UNDEFINED"); // std::is_same<>();
		}
	};
}
