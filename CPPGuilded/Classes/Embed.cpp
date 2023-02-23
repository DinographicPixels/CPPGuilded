//
// Created by PakkoGraphic on 2/20/23.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "Embed.hpp"

CPPGuilded::Embed::Embed(const string& title, const string& description)
{
	this->title = title;
	this->description = description;
}

CPPGuilded::Embed::Embed(const json& embed)
{
	this->title = utils.get_or_else<std::string>(embed, "title", "");
	this->description = utils.get_or_else<std::string>(embed, "description", "");
	this->url = utils.get_or_else<std::string>(embed, "url", "");
	this->color = utils.get_or_else<int>(embed, "color", 0);
	this->timestamp = utils.get_or_else<std::string>(embed, "timestamp", "");

	// FIELDS
	if (utils.has_value(embed, "fields")){
		for (json field : embed.at("fields")){
			fieldsField f;
			field.at("name").get_to<std::string>(f.name);
			field.at("value").get_to<std::string>(f.value);
			field.at("inline").get_to<bool>(f.isInline);
			fields.push_back(f);
		}
	}

	// FOOTER
	if (utils.has_value(embed, "footer")){
		json jsonFooter = embed.at("footer");
		footer.text = utils.get_or_else<std::string>(jsonFooter, "text", "");
		footer.icon_url = utils.get_or_else<std::string>(jsonFooter, "icon_url", "");
	}

	// THUMBNAIL
	if (utils.has_value(embed, "thumbnail")){
		json jsonThumbnail = embed.at("thumbnail");
		thumbnail.url = utils.get_or_else<std::string>(jsonThumbnail, "url", "");
	}

	// IMAGE
	if (utils.has_value(embed, "image")){
		json jsonImage = embed.at("image");
		image.url = utils.get_or_else<std::string>(jsonImage, "url", "");
	}

	//AUTHOR
	if (utils.has_value(embed, "author")){
		json jsonAuthor = embed.at("author");
		author.name = utils.get_or_else<std::string>(jsonAuthor, "name", "");
		author.url = utils.get_or_else<std::string>(jsonAuthor, "url", "");
		author.icon_url = utils.get_or_else<std::string>(jsonAuthor, "icon_url", "");
	}
}

json CPPGuilded::Embed::to_json() {
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