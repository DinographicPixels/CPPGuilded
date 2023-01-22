#pragma once
#include "static.hpp"

namespace CPPGuilded {
	class Utils {
	  public:
		DLL_EXPORT Utils() {};
		template<typename T> T getValue(const nlohmann::json& data, std::string name) {
			if constexpr (std::is_same<T, std::string>()){
				return data.value(name, "UNDEFINED"); // std::is_same<>();
			}else if constexpr (std::is_same<T, int>()){
				return data.value(name, 0);
			} else if constexpr (std::is_same<T, bool>()){
				return data.value(name, false);
			}
		}
	};
}
