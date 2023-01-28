#include <iostream>
#include "../CPPGuilded/library.hpp"
#include "../CPPGuilded/Classes/WSManager.hpp"

using namespace CPPGuilded;

int main() {
    // bool result = CPPGuilded::Client();
    CPPGuilded::Client* client = new CPPGuilded::Client("gapi_jQlwqi1jzqrm6eTeWdQZ+rHrqwofVNlFGIFeCBSxLeuHGVVFOQsRSH4pm8iGIYokw3wAt6A/lbVsUDH4EjZipg==");
	client->createMessage("b1df1cbb-9074-4692-b6a0-3997a47cacf1", {"hi", {"0fbfb1eb-b884-42ec-a89d-253edd329997"}, false, false});
    // client->hello(true);
    // std::cout << result << std::endl;
    std::cout << "test success" << std::endl;

	std::cout << "websocket test started" << std::endl;

	CPPGuilded::WSManager* ws = new WSManager("gapi_jQlwqi1jzqrm6eTeWdQZ+rHrqwofVNlFGIFeCBSxLeuHGVVFOQsRSH4pm8iGIYokw3wAt6A/lbVsUDH4EjZipg==");
}