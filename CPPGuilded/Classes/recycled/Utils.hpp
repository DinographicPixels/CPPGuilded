#pragma once
#include <iostream>
#include <map>

#include "static.h"
#include "library.h"
using namespace std;

namespace CPPGuilded {
    class Utils {
    public:
        template<class T> T getValue(const json &data, std::string name);
        // DLL_EXPORT Utils();
    };
}