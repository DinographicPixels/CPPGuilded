//
// Created by PakkoGraphic on 2/20/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#pragma once

#ifndef CPPGUILDED_EMBED_HPP
#define CPPGUILDED_EMBED_HPP

#include <iostream>
#include "static.hpp"
#include "Classes/Utils.hpp"

namespace CPPGuilded
{
	class Embed {
	 private:
		CPPGuilded::Utils utils;
	 protected:
		struct fieldsField {
			string name;
			string value;
			bool isInline;
			// NLOHMANN_DEFINE_TYPE_INTRUSIVE(fieldsField, name, value, isInline);
		};
		struct footerStruct {
			string text;
			string icon_url;
			// NLOHMANN_DEFINE_TYPE_INTRUSIVE(footerStruct, icon_url, text);
		};
		struct thumbnailStruct {
			string url;
			// NLOHMANN_DEFINE_TYPE_INTRUSIVE(thumbnailStruct, url);
		};
		struct imageStruct {
			string url;
			// NLOHMANN_DEFINE_TYPE_INTRUSIVE(imageStruct, url);
		};
		struct authorStruct {
			string name;
			string url;
			string icon_url;
			// NLOHMANN_DEFINE_TYPE_INTRUSIVE(authorStruct, name, url, icon_url);
		};
	 public:
		string title;
		string description;
		string url;
		int color;
		string timestamp;
		vector<fieldsField> fields;
		footerStruct footer;
		thumbnailStruct thumbnail;
		imageStruct image;
		authorStruct author;
		// NLOHMANN_DEFINE_TYPE_INTRUSIVE(Embed, title, description, url, color, timestamp, fields, footer, thumbnail, image, author);
		// DLL_EXPORT Embed(string title);
		DLL_EXPORT json to_json();
		Embed(const string& title = "", const string& description = "");
		Embed(const json& embed);
	};

} // CPPGuilded

#endif //CPPGUILDED_EMBED_HPP
