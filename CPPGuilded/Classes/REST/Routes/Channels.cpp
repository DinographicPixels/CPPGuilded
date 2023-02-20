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

CPPGuilded::Channels::Channels(CPPGuilded::Client* client, std::shared_ptr<CPPGuilded::RequestHandler> manager): client(client), manager(manager) {};

CPPGuilded::Message CPPGuilded::Channels::create_message(std::string channelID, MethodOptions::CreateMessage options) {
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
	RequestHandler::GuildedHTTPResponse req = manager->request("POST", "/channels/" + channelID + "/messages", jsonOptions.dump());
	json res = json::parse(req.body).at("message");

	return Message(res, client);
}

CPPGuilded::Message CPPGuilded::Channels::edit_message(std::string channelID, std::string messageID, MethodOptions::EditMessage options) {
	json jsonOptions = options;
	if (options.embeds.size() >= 1) {
		for (auto x: options.embeds){
			json jsonEmbed = x.to_json();
			jsonOptions["embeds"].push_back(jsonEmbed);
		}
	}
	RequestHandler::GuildedHTTPResponse req = manager->request("PUT", "/channels/" + channelID + "/messages/" + messageID, jsonOptions.dump());
	json res = json::parse(req.body).at("message");

	return Message(res, client);
}

void CPPGuilded::Channels::delete_message(std::string channelID, std::string messageID) {
	manager->request("DELETE", "/channels/" + channelID + "/messages/" + messageID);
}

CPPGuilded::Message CPPGuilded::Channels::get_message(std::string channelID, std::string messageID) {
	RequestHandler::GuildedHTTPResponse req = manager->request("GET", "/channels/" + channelID + "/messages/" + messageID);
	json res = json::parse(req.body).at("message");
	return Message(res, client);
}

std::vector<CPPGuilded::Message> CPPGuilded::Channels::get_messages(std::string channelID, MethodFilters::GetChannelMessages filter) {
	RequestHandler::GuildedHTTPResponse req = manager->request("GET", "/channels/" + channelID + "/messages");
	json res = json::parse(req.body).at("messages");
	std::vector<CPPGuilded::Message> messages;
	for (json jsonMsg: res){
		messages.push_back(Message(jsonMsg, client));
	}
	return messages;
}

CPPGuilded::Channel CPPGuilded::Channels::create_channel(MethodOptions::CreateChannel options)
{
	json jsonOptions = options;
	RequestHandler::GuildedHTTPResponse req = manager->request("POST", "/channels", jsonOptions);
	json res = json::parse(req.body).at("channel");
	return Channel(res, client);
}

CPPGuilded::Channel CPPGuilded::Channels::edit_channel(std::string channelID, MethodOptions::EditChannel options)
{
	json jsonOptions = options;
	RequestHandler::GuildedHTTPResponse req = manager->request("PATCH", "/channels/" + channelID, jsonOptions);
	json res = json::parse(req.body).at("channel");
	return Channel(res, client);
}

void CPPGuilded::Channels::delete_channel(std::string channelID)
{
	manager->request("PATCH", "/channels/" + channelID);
}