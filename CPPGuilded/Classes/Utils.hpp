#pragma once
#include "static.hpp"

#include <iostream>

#include "Message.hpp"
using namespace std;

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
			} else if constexpr (std::is_same<T, vector<string>>()){
				vector<string> defVal = {};
				return data.value(name, defVal);
			} else if constexpr (std::is_same<T, vector<int>>()){
				vector<int> defVal = {};
				return data.value(name, defVal);
			} else if constexpr (std::is_same<T, vector<Message::EmbedStructure>>()) {
				vector<Message::EmbedStructure> defVal = {};
				return data.value(name, defVal);
			} else {
				return data.value(name, "UNDEFINED");
			}
		}
	};
}
