#include <iostream>
#include "../CPPGuilded/library.hpp"
#include "Classes/Gateway/WSManager.hpp"
#include "Classes/Member.hpp"

using namespace CPPGuilded;

std::string token = "gapi_jQlwqi1jzqrm6eTeWdQZ+rHrqwofVNlFGIFeCBSxLeuHGVVFOQsRSH4pm8iGIYokw3wAt6A/lbVsUDH4EjZipg==";

class BotClient: public Client {
  public:
	BotClient(std::string token): Client(token) {
		this->token = token;
	};
	void on_message_create(CPPGuilded::Message message) override {
		Message::Embed messageEmbed = Message::Embed();
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

		CPPGuilded::Member messageAuthor = this->get_member(message.guildID, message.createdBy);
		if (messageAuthor.type == "bot") return;
		Message greetingMessage = this->create_message("b1df1cbb-9074-4692-b6a0-3997a47cacf1", { "hi" });
		this->create_message("b1df1cbb-9074-4692-b6a0-3997a47cacf1", { "hi", { "0fbfb1eb-b884-42ec-a89d-253edd329997" }, false, false, {messageEmbed }});
		this_thread::sleep_for(chrono::seconds(1));
		this->edit_message(greetingMessage.channelID, greetingMessage.id, { "bye!" });
		this_thread::sleep_for(chrono::seconds(1));
		this->delete_message(greetingMessage.channelID, greetingMessage.id);
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