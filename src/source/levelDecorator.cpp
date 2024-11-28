//
// Created by l1Akr on 24-8-10.
//

#include "levelDecorator.h"
#include "regex"
#include "packer.h"

namespace logger {
    void levelDecorator::format(std::map<std::string, std::variant<int, std::string, std::thread::id>> &events) {
        std::regex r("(%level)");
        std::smatch match;
        if(std::regex_search(str, match, r)){
            auto it = events.find("level");
            if(it == events.end() || !std::holds_alternative<int>(it->second)) return;
            const auto& value = it->second;
            int tmp = std::get<int>(value);
            const char* name = LevelToName[tmp];
//            std::cout << tmp << std::endl;
            str = std::move(std::regex_replace(str, r, name));
        }
    }
} // logger