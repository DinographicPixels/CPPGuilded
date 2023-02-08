#pragma once
#include "static.hpp"

namespace CPPGuilded {
	class Client;
    class Message {
    public:
	  class Embed {
		protected:
		  struct FIELDS_FIELD {
			  string name;
			  string value;
			  bool isInline;
			  // NLOHMANN_DEFINE_TYPE_INTRUSIVE(fields, name, value);
		  };
		  struct FOOTERSTRUCT {
			  string text;
			  string icon_url;
			  // NLOHMANN_DEFINE_TYPE_INTRUSIVE(footer, icon_url);
		  };
		  struct THUMBNAILSTRUCT {
			  string url;
			  // NLOHMANN_DEFINE_TYPE_INTRUSIVE(thumbnail, url);
		  };
		  struct IMAGESTRUCT {
			  string url;
			  // NLOHMANN_DEFINE_TYPE_INTRUSIVE(image, url);
		  };
		  struct AUTHORSTRUCT {
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
		  vector<FIELDS_FIELD> fields;
		  FOOTERSTRUCT footer;
		  THUMBNAILSTRUCT thumbnail;
		  IMAGESTRUCT image;
		  AUTHORSTRUCT author;
		  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Embed, title, description);
		  // DLL_EXPORT Embed(string title);
		  DLL_EXPORT json to_json();
	  };
        string id;
        string type;
        string serverID;
        string channelID;
        string content;
        vector<Embed> embeds;
        vector<string> replyMessageIDs;
        bool isPrivate;
        bool isSilent;
        string mentions;
        string createdAt;
        string createdBy;
        string createdByWebhookID;
        string updatedAt;
        DLL_EXPORT Message(const json& data, Client* client);
    };
}
