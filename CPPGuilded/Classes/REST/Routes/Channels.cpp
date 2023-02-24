//
// Created by PakkoGraphic on 2/10/2023.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include "Channels.hpp"

#include <iostream>
#include "static.hpp"

#include "Classes/Message.hpp"
#include "Classes/Channel.hpp"
#include "Classes/RequestHandler.hpp"
#include "Classes/Embed.hpp"
#include "Classes/ForumThread.hpp"

CPPGuilded::Channels::Channels(CPPGuilded::Client* client, std::shared_ptr<CPPGuilded::RequestHandler> manager): client(client), manager(std::move(manager)) {
	log = Utils::Logger("REST/Channels | CPPGuilded");
};

CPPGuilded::Message CPPGuilded::Channels::create_message(const std::string& channelID, const MethodOptions::CreateMessage& options) {
	json jsonOptions = options;
	if (options.replyMessageIds.empty()) jsonOptions.erase("replyMessageIds");
	if (options.embeds.size() >= 1){
		for (auto x: options.embeds){
			json jsonEmbed = x.to_json();
			jsonOptions["embeds"].push_back(jsonEmbed);
		}
		// json jsonEmbed = json{*messageEmbed};
		//jsonOptions["embeds"] = jsonEmbed;
	}
	RequestHandler::GuildedHTTPResponse req = manager->request("POST", "/channels/" + channelID + "/messages", jsonOptions.dump(4, ' '));
	json res = json::parse(req.body).at("message");

	return Message{res, client};
}

CPPGuilded::Message CPPGuilded::Channels::edit_message(const std::string& channelID, const std::string& messageID, const MethodOptions::EditMessage& options) {
	json jsonOptions = options;
	if (options.embeds.size() >= 1) {
		for (auto x: options.embeds){
			json jsonEmbed = x.to_json();
			jsonOptions["embeds"].push_back(jsonEmbed);
		}
	}
	RequestHandler::GuildedHTTPResponse req = manager->request("PUT", "/channels/" + channelID + "/messages/" + messageID, jsonOptions.dump(4, ' '));
	json res = json::parse(req.body).at("message");

	return Message{res, client};
}

void CPPGuilded::Channels::delete_message(const std::string& channelID, const std::string& messageID) {
	manager->request("DELETE", "/channels/" + channelID + "/messages/" + messageID);
}

CPPGuilded::Message CPPGuilded::Channels::get_message(const std::string& channelID, const std::string& messageID) {
	RequestHandler::GuildedHTTPResponse req = manager->request("GET", "/channels/" + channelID + "/messages/" + messageID);
	json res = json::parse(req.body).at("message");
	return Message{res, client};
}

std::vector<CPPGuilded::Message> CPPGuilded::Channels::get_messages(const std::string& channelID, const MethodFilters::GetChannelMessages& filter) {
	RequestHandler::GuildedHTTPResponse req = manager->request("GET", "/channels/" + channelID + "/messages");
	json res = json::parse(req.body).at("messages");
	std::vector<CPPGuilded::Message> messages;
	for (const json& jsonMsg: res){
		messages.emplace_back(Message(jsonMsg, client));
	}
	return messages;
}

CPPGuilded::Channel CPPGuilded::Channels::create_channel(const MethodOptions::CreateChannel& options)
{
	json jsonOptions;
	// Required properties. (if they aren't set, the API will return an error)
	if (options.name.size() >= 1) jsonOptions["name"] = options.name;
	if (options.type.size() >= 1) jsonOptions["type"] = options.type;
	// Optional properties:
	if (options.serverId) jsonOptions["serverId"] = options.serverId.value();
	if (options.topic) jsonOptions["topic"] = options.topic.value();
	if (options.categoryId) jsonOptions["categoryId"] = options.categoryId.value();
	if (options.groupId) jsonOptions["groupId"] = options.groupId.value();
	if (options.isPublic) jsonOptions["isPublic"] = options.isPublic.value();
	std::cout << jsonOptions << std::endl;
	RequestHandler::GuildedHTTPResponse req = manager->request("POST", "/channels", jsonOptions.dump(4, ' '));
	json res = json::parse(req.body).at("channel");
	return Channel{res, client};

}

CPPGuilded::Channel CPPGuilded::Channels::edit_channel(const std::string& channelID, const MethodOptions::EditChannel& options)
{
	json jsonOptions;
	if (options.name) jsonOptions["name"] = options.name.value();
	if (options.topic) jsonOptions["topic"] = options.topic.value();
	if (options.isPublic) jsonOptions["isPublic"] = options.isPublic.value();

	RequestHandler::GuildedHTTPResponse req = manager->request("PATCH", "/channels/" + channelID, jsonOptions.dump(4, ' '));
	json res = json::parse(req.body).at("channel");
	return Channel{res, client};
}

void CPPGuilded::Channels::delete_channel(const std::string& channelID)
{
	manager->request("DELETE", "/channels/" + channelID);
}

CPPGuilded::Channel CPPGuilded::Channels::get_channel(const std::string& channelID)
{
	RequestHandler::GuildedHTTPResponse req = manager->request("GET", "/channels/" + channelID);
	json res = json::parse(req.body).at("channel");
	return Channel{res, client};
}

CPPGuilded::ForumThread CPPGuilded::Channels::create_forum_thread(const std::string& channelID,
	const std::string& title,
	const std::string& content)
{
	if (title.empty() || content.empty()) throw CPPGuilded::GuildedException("REST request failed: title and content are required properties.");
	RequestHandler::GuildedHTTPResponse req = manager->request("POST", "/channels/" + channelID + "/topics", json{{"title", title}, {"content", content}});
	json res = json::parse(req.body).at("forumTopic");
	return ForumThread{res, client};
}

CPPGuilded::ForumThread CPPGuilded::Channels::edit_forum_thread(const std::string& channelID,
	const std::string& threadID,
	const std::optional<std::string>& title,
	const std::optional<std::string>& content)
{
	json requestOptions;
	if (title) requestOptions.push_back({"title", title.value()});
	if (content) requestOptions.push_back({"content", content.value()});

	RequestHandler::GuildedHTTPResponse req = manager->request("PATCH", "/channels/" + channelID + "/topics/" + threadID, requestOptions);
	json res = json::parse(req.body).at("forumTopic");

	return ForumThread{res, client};
}

void CPPGuilded::Channels::delete_forum_thread(const std::string& channelID, const std::string& threadID)
{
	manager->request("DELETE", "/channels/" + channelID + "/topics/" + threadID);
}