#include <iostream>
#include "../CPPGuilded/library.hpp"
#include "Classes/Gateway/WSManager.hpp"

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
		messageEmbed.url = "https://touchguild.com";
		messageEmbed.fields = {{"field 1", "value 1", true}, { "field 2", "value 2", true }};
		messageEmbed.footer = {"FOOTER TEXT"};
		this->createMessage("b1df1cbb-9074-4692-b6a0-3997a47cacf1", { "hi", { "0fbfb1eb-b884-42ec-a89d-253edd329997" }, false, false, {messageEmbed} });
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