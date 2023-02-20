//
// Created by PakkoGraphic on 2/20/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#ifndef CPPGUILDED_EMBED_HPP
#define CPPGUILDED_EMBED_HPP

#include <iostream>
#include "static.hpp"

namespace CPPGuilded
{
	class Embed {
	 protected:
		struct fieldsField {
			string name;
			string value;
			bool isInline;
			// NLOHMANN_DEFINE_TYPE_INTRUSIVE(fields, name, value);
		};
		struct footerStruct {
			string text;
			string icon_url;
			// NLOHMANN_DEFINE_TYPE_INTRUSIVE(footer, icon_url);
		};
		struct thumbnailStruct {
			string url;
			// NLOHMANN_DEFINE_TYPE_INTRUSIVE(thumbnail, url);
		};
		struct imageStruct {
			string url;
			// NLOHMANN_DEFINE_TYPE_INTRUSIVE(image, url);
		};
		struct authorStruct {
			string name;
			string url;
			string icon_url;
			// NLOHMANN_DEFINE_TYPE_INTRUSIVE(author, name, url, icon_url);
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
		NLOHMANN_DEFINE_TYPE_INTRUSIVE(Embed, title, description);
		// DLL_EXPORT Embed(string title);
		DLL_EXPORT json to_json();
	};

} // CPPGuilded

#endif //CPPGUILDED_EMBED_HPP
