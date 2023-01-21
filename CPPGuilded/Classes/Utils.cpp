#include "Utils.hpp"
#include "static.hpp"
#include <iostream>

#include "Exceptions.hpp"

// #include "library.hpp"

template<typename T> T CPPGuilded::Utils::getValue(const json& data, std::string name) {
	if (std::is_same<T, string>()){
		return data.value(name, "UNDEFINED");
	}else if (std::is_same<T, int>()){
		return data.value(name, 0);
	}else if (std::is_same<T, bool>()){
		return data.value(name, false);
	}
	throw "Type isn't recognized.";
}
