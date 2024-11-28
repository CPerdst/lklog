//
// Created by leakerma on 8/9/2024.
//

#include "formator.h"
#include "iostream"

namespace logger {
    std::string formator::operation(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) {
        return strs;
    }

    std::string formator::format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) {
        std::string r = vec.back()->operation(events);
        return std::move(r);
    }

    void formator::setStr(std::string s) {
        std::string tmp = std::move(s);
//        std::cout << tmp << std::endl;
//        strs.append("asd");
//        std::cout << strs << std::endl;
        strs = std::move(tmp);
    }

    std::string formator::getStr() {
        return strs;
    }
} // logger