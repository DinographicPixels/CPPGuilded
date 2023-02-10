#include "Utils.h"
#include "static.h"
#include <iostream>

// #include "library.h"
using namespace std;

template<class T> T CPPGuilded::Utils::get_value(const json &data, std::string name) {
    if (std::is_same<T, string>()){
        return data.value(name, "UNDEFINED");
    }else if (std::is_same<T, int>()){
        return data.value(name, 0);
    }else if (std::is_same<T, bool>()){
        return data.value(name, false);
    }
    throw "Type isn't recognized.";
}