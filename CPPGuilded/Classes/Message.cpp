#include "Message.hpp"
#include "static.hpp"
#include <iostream>

#include "Exceptions.hpp"

#include "library.hpp"

CPPGuilded::Message::Message(const json &data, Client* client) {
    id = client->utils->getValue<std::string>(data, "id");
    type = client->utils->getValue<std::string>(data, "type");
    serverID = client->utils->getValue<std::string>(data, "serverId");
    channelID = client->utils->getValue<std::string>(data, "chnannelId");
    content = client->utils->getValue<std::string>(data, "content");
    embeds = client->utils->getValue<vector<Embed>>(data, "embeds");
    replyMessageIDs = client->utils->getValue<vector<string>>(data, "replyMessageIds");
    isPrivate = client->utils->getValue<bool>(data, "isPrivate");
    isSilent = client->utils->getValue<bool>(data, "isSilent");
    mentions = client->utils->getValue<std::string>(data, "mentions");
    createdAt = client->utils->getValue<std::string>(data, "createdAt");
    createdBy = client->utils->getValue<std::string>(data, "createdBy");
    createdByWebhookID = client->utils->getValue<std::string>(data, "createdByWebhookId");
    updatedAt = client->utils->getValue<std::string>(data, "updatedAt");
}

json CPPGuilded::Message::Embed::to_json() {
	json jsonEmbed;
	// SIMPLE PROPERTIES
	if (this->title.length() > 0) jsonEmbed["title"] = this->title;
	if (this->description.length() > 0) jsonEmbed["description"] = this->description;
	if (this->url.length() > 0) jsonEmbed["url"] = this->url;
	if (this->color) jsonEmbed["color"] = this->color;

	// FIELDS
	for (unsigned int i = 0; i < this->fields.size(); i++){
		json jsonFields;
		jsonFields["name"] = fields[i].name;
		jsonFields["value"] = fields[i].value;
		jsonFields["inline"] = fields[i].isInline;
		jsonEmbed["fields"].emplace_back(jsonFields);
	}

	// FOOTER
	json jsonFooter;
	if (this->footer.text.size() > 0) jsonFooter["text"] = this->footer.text;
	if (this->footer.icon_url.size() > 0) jsonFooter["icon_url"] = this->footer.icon_url;
	if (this->footer.icon_url.size() > 0 || this->footer.text.size() > 0) jsonEmbed["footer"] = jsonFooter;

	return jsonEmbed;
}