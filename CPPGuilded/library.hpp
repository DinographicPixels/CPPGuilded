#pragma once
#include <iostream>
#include <map>

#include "static.hpp"
// #include "Classes/Utils.hpp"
// #ifndef cppguilded
// #define cppguilded

#include "Classes/Utils.hpp"

#include <boost/beast/http.hpp>
using namespace boost;

namespace http = boost::beast::http;

namespace CPPGuilded {
    class Client {
    private:
        struct GuildedHTTPResponse {
            unsigned int status_code;
            std::map<std::string, std::string> headers;
            std::string body;
        };
    public:
        DLL_EXPORT Client(string TOKEN);
        std::string token;
        CPPGuilded::Utils* utils;
        bool hello(bool sus);
        GuildedHTTPResponse request(const string method, const string target, const string& data = "");
    };
}

// #endif //CPPGUILDED_LIBRARY_H
