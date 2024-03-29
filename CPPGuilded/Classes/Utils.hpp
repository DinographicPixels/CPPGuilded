//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once
#ifndef CPPGUILDED_UTILS_HPP
#define CPPGUILDED_UTILS_HPP

#include "static.hpp"

#include <iostream>
#include <thread>
#include <mutex>
#include <map>

using namespace std;

enum Loglevel {
	Debug,
	Info,
	Warning,
	Error
};

namespace CPPGuilded {
	class Utils {
	  public:
		DLL_EXPORT Utils() {};
		template<typename T> T get_value(const nlohmann::json& data, std::string name) {
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
			}else{
				return data.value(name, "UNDEFINED");
			}
		}

		template <class T>
		DLL_EXPORT T get_or_else(const json& j, const std::string& key, const T& _default) {
			if (j.count(key) == 0 || j.at(key).is_null())
				return _default;
			else
				return j.at(key).get<T>();
		}

		template <class T>
		DLL_EXPORT std::optional<T> get_optional(const json& j, const std::string& key) {
			if (j.count(key) == 0 || j.at(key).is_null())
				return {};
			else
				return std::make_optional<T>(j.at(key).get<T>());
		}

		DLL_EXPORT inline bool has_value(const json& j, const std::string& key) {
			return j.count(key) > 0 && !j.at(key).is_null();
		}

		class Logger {
		  protected:
			std::string _name;

		  public:
			DLL_EXPORT void register_thread(const std::thread::id& id, const std::string& name);
			DLL_EXPORT void unregister_thread(const std::thread::id& id);

			DLL_EXPORT static void set_log_level(const Loglevel& level);

			DLL_EXPORT Logger(){};
			DLL_EXPORT Logger(const std::string&);

			DLL_EXPORT void print(const Loglevel level, const std::string& message);

			DLL_EXPORT void debug(const std::string& message);
			DLL_EXPORT void info(const std::string& message);
			DLL_EXPORT void warning(const std::string& message);
			DLL_EXPORT void error(const std::string& message);
		};
	};
}

#endif