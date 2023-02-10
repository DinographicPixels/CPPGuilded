#pragma once

#ifndef CPPGUILDED_STATIC_HPP
#define CPPGUILDED_STATIC_HPP

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

#include <boost/asio/ssl/context.hpp>
#include <nlohmann/json.hpp>
#include <exception>

#define GUILDED_HOST "www.guilded.gg"
#define GUILDED_APIVERSION 1

using json = nlohmann::json;
using namespace std;

DLL_EXPORT void load_ssl_certificates(boost::asio::ssl::context& ssl_context);

#endif
