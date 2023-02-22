//
// Created by PakkoGraphic.
// Copyright (c) 2023 DinographicPixels. All rights reserved.
//

#include <iostream>
#include "index.h"
#include "../CPPGuilded/library.hpp"
#include "Classes/Gateway/WSManager.hpp"
#include "Classes/Member.hpp"

using namespace CPPGuilded;

std::string token = "gapi_jQlwqi1jzqrm6eTeWdQZ+rHrqwofVNlFGIFeCBSxLeuHGVVFOQsRSH4pm8iGIYokw3wAt6A/lbVsUDH4EjZipg==";

#include "Classes/Exceptions.hpp"

class BotClient: public Client {
  public:
	BotClient(std::string token): Client(token) {
		this->token = token;
	};
	void on_message_create(CPPGuilded::Message message) override {
		Embed messageEmbed = Embed();
		messageEmbed.title = "embed testin'";
		messageEmbed.description = "this is a desc";
		messageEmbed.color = 6118369;
		messageEmbed.url = "https://touchguild.com";
		messageEmbed.fields = {{"field 1", "value 1", true}, { "field 2", "value 2", true }};
		messageEmbed.footer = {"FOOTER TEXT", "https://img.guildedcdn.com/ContentMediaGenericFiles/312797c11c3f01d6b14f5719529a76ab-Full.webp?w=1080&h=1080" };
		messageEmbed.thumbnail = {"https://img.guildedcdn.com/ContentMediaGenericFiles/312797c11c3f01d6b14f5719529a76ab-Full.webp?w=1080&h=1080"};
		messageEmbed.image = {"https://camo.githubusercontent.com/739ac07c7fb99a25939e49d97e67d6a0f0968437ea15fc175f818dd737917f85/68747470733a2f2f63646e2e676c697463682e676c6f62616c2f62633638333133652d366162622d343838632d613165332d6536643130383137633262642f746f7563686775696c642d637261646975732e706e673f763d31363635333131323732323437"};
		messageEmbed.author = {
			"DinographicPixels",
			"https://www.guilded.gg/DinographicPixels",
			"https://www.guilded.gg/asset/Default/Gil-md.png"
		};

		CPPGuilded::Member messageAuthor = get_member_test(message);
		if (messageAuthor.bot == true) return;

		/**
		Message greetingMessage = message_create_test();
		advanced_message_create_test(messageEmbed);
		this_thread::sleep_for(chrono::seconds(1));

		edit_message_test(greetingMessage);
		this_thread::sleep_for(chrono::seconds(1));

		get_message_test(greetingMessage);
		this_thread::sleep_for(chrono::seconds(1));

		delete_message_test(greetingMessage);
		this_thread::sleep_for(chrono::seconds(1));

		get_messages_test(greetingMessage);
		this_thread::sleep_for(chrono::seconds(1));

		User user = get_user_test(greetingMessage.createdBy);
		std::cout << user.type; // breakpoint here.
		this_thread::sleep_for(chrono::seconds(1));
		*/
		// cursed method
		//channel_tests();
		//this_thread::sleep_for(chrono::seconds(1));

		get_guild_test(message.guildID.value());
		this_thread::sleep_for(chrono::seconds(1));
	}

	Message message_create_test() {
		return this->create_message("b1df1cbb-9074-4692-b6a0-3997a47cacf1", { "hi" });
	}

	Message advanced_message_create_test(CPPGuilded::Embed messageEmbed) {
		return this->create_message("b1df1cbb-9074-4692-b6a0-3997a47cacf1", { "hi", { "0fbfb1eb-b884-42ec-a89d-253edd329997" }, false, false, { messageEmbed }});
	}

	Message edit_message_test(Message greetingMessage) {
		return this->edit_message(greetingMessage.channelID, greetingMessage.id, { "bye!" });
	}

	void delete_message_test(Message greetingMessage) {
		this->delete_message(greetingMessage.channelID, greetingMessage.id);
	}

	void get_message_test(Message greetingMessage) {
		Message fetchMessage = this->get_message(greetingMessage.channelID, greetingMessage.id);
		std::cout << "fetchMessage: " << fetchMessage.id << std::endl;
	}

	void get_messages_test(Message greetingMessage) {
		std::vector<Message> fetchMessages = this->get_messages(greetingMessage.channelID, {});
		std::cout << "fetchMESSAGES: " << fetchMessages.size() << std::endl;
	}

	Member get_member_test(Message message) {
		return this->get_member(message.guildID.value(), message.createdBy);
	}

	User get_user_test(const std::string& userID) {
		User user = get_user(userID);
		std::cout << "my user id: " << user.id << std::endl;
		return user;
	}

	void channel_tests(){
		std::cout << "running.." << std::endl;
		MethodOptions::CreateChannel options;
		options.serverId = "aE9VwoAj";
		options.name = "name";
		options.type = "chat";
		Channel createdChannel = this->create_channel(options);
		std::cout << "channel id here: "  << createdChannel.id << std::endl; // breakpoint here.
		std::cout << "channel_tests" << std::endl;
		this_thread::sleep_for(chrono::seconds(1));
		this->edit_channel(createdChannel.id, { "new name" });
		this_thread::sleep_for(chrono::seconds(1));
		this->delete_channel(createdChannel.id);
	}

	void get_guild_test(const std::string& guildID) {
		std::cout << "get guild is running.." << std::endl;
		CPPGuilded::Guild retrievedGuild = this->rest.guilds.get_guild(guildID);
		if (retrievedGuild.type) std::cout << "type is defined" << std::endl; else std::cout << "type isn't defined" << std::endl;
		std::cout << "optional value, type: " << retrievedGuild.type.value() << std::endl;
	}
};

int main() {
    // bool result = CPPGuilded::Client();
    BotClient client = BotClient(token);
    // client->hello(true);
    // std::cout << result << std::endl;
    // std::cout << "test success" << std::endl;

	// std::cout << "websocket test started" << std::endl;

	client.connect();

	while (1) {
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}

	// CPPGuilded::WSManager* ws = new WSManager("gapi_jQlwqi1jzqrm6eTeWdQZ+rHrqwofVNlFGIFeCBSxLeuHGVVFOQsRSH4pm8iGIYokw3wAt6A/lbVsUDH4EjZipg==");
	//string wsState = ws->getState() ? "true": "false";
	//std::cout << "state: " << wsState << std::endl;
	return 0;
}