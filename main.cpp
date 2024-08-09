#include <iostream>
#include "logger/formator.h"



int main() {
    std::cout << "Hello, World!" << std::endl;
    logger::formator f{};
    f.setStr(std::string("asd"));
    f.format();
    std::cout << f.getStr() << std::endl;
    return 0;
}
