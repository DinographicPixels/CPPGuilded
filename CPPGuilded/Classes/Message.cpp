#include "Message.hpp"
#include "static.hpp"
#include <iostream>

#include "Exceptions.hpp"

#include "library.hpp"

CPPGuilded::Message::Message(const json &data, Client* client) {
    id = client->utils->get_value<std::string>(data, "id");
    type = client->utils->get_value<std::string>(data, "type");
    guildID = client->utils->get_value<std::string>(data, "serverId");
    channelID = client->utils->get_value<std::string>(data, "channelId");
    content = client->utils->get_value<std::string>(data, "content");
    embeds = client->utils->get_value<vector<Embed>>(data, "embeds");
    replyMessageIDs = client->utils->get_value<vector<string>>(data, "replyMessageIds");
    isPrivate = client->utils->get_value<bool>(data, "isPrivate");
    isSilent = client->utils->get_value<bool>(data, "isSilent");
    mentions = client->utils->get_value<std::string>(data, "mentions");
    createdAt = client->utils->get_value<std::string>(data, "createdAt");
    createdBy = client->utils->get_value<std::string>(data, "createdBy");
    createdByWebhookID = client->utils->get_value<std::string>(data, "createdByWebhookId");
    updatedAt = client->utils->get_value<std::string>(data, "updatedAt");
}

json CPPGuilded::Message::Embed::to_json() {
	json jsonEmbed;
	// SIMPLE PROPERTIES
	if (this->title.length() > 0) jsonEmbed["title"] = this->title;
	if (this->description.length() > 0) jsonEmbed["description"] = this->description;
	if (this->url.length() > 0) jsonEmbed["url"] = this->url;
	if (this->color) jsonEmbed["color"] = this->color;
	if (this->timestamp.length() > 0) jsonEmbed["timestamp"] = this->timestamp;

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

	// THUMBNAIL
	if (this->thumbnail.url.size() > 0){
		json jsonThumbnail;
		jsonThumbnail["url"] = thumbnail.url;
		jsonEmbed["thumbnail"] = jsonThumbnail;
	}

	// IMAGE
	if (this->image.url.size() > 0) {
		json jsonImage;
		jsonImage["url"] = this->image.url;
		jsonEmbed["image"] = jsonImage;
	}

	// AUTHOR
	json jsonAuthor;
	if (this->author.url.size() > 0) jsonAuthor["url"] = this->author.url;
	if (this->author.icon_url.size() > 0) jsonAuthor["icon_url"] = this->author.icon_url;
	if (this->author.name.size() > 0) jsonAuthor["name"] = this->author.name;
	if (this->author.icon_url.size() > 0 || this->author.url.size() > 0 || this->author.name.size() > 0) jsonEmbed["author"] = jsonAuthor;

	return jsonEmbed;
}