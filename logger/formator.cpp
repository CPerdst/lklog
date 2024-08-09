//
// Created by leakerma on 8/9/2024.
//

#include "formator.h"
#include "iostream"

namespace logger {
    std::string formator::operation(std::string &event) {
        return str;
    }

    void formator::format() {
        std::string s = std::string("dsa");
        std::string r = vec.back()->operation(s);
        std::cout << r << std::endl;
    }

    void formator::setStr(std::string s) {
        str = std::move(s);
    }

    std::string formator::getStr() {
        return str;
    }
} // logger