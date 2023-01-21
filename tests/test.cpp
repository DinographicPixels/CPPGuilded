#include <iostream>
#include "../CPPGuilded/library.h"

using namespace CPPGuilded;

int main() {
    // bool result = CPPGuilded::Client();
    CPPGuilded::Client* client = new CPPGuilded::Client();
    client->hello(true);
    // std::cout << result << std::endl;
    std::cout << "test success" << std::endl;
    return 1;
}