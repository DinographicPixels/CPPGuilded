#include <iostream>
#include "../CPPGuilded/library.hpp"

using namespace CPPGuilded;

int main() {
    // bool result = CPPGuilded::Client();
    CPPGuilded::Client* client = new CPPGuilded::Client("gapi_jQlwqi1jzqrm6eTeWdQZ+rHrqwofVNlFGIFeCBSxLeuHGVVFOQsRSH4pm8iGIYokw3wAt6A/lbVsUDH4EjZipg==");
    client->hello(true);
    // std::cout << result << std::endl;
    std::cout << "test success" << std::endl;
    return 1;
}