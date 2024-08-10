//
// Created by l1Akr on 24-8-10.
//

#include "lineDecorator.h"
#include "regex"

namespace logger {
    void lineDecorator::format(std::map<std::string, std::variant<int, std::string, std::thread::id>> &events) {
        std::regex r("(%line|%linenum)");
        std::smatch match;
        if(std::regex_search(str, match, r)){
            auto it = events.find("line");
            if(it == events.end() || !std::holds_alternative<int>(it->second)) return;
            const auto& value = it->second;
            int line = std::get<int>(value);
//            std::cout << tmp << std::endl;
            str = std::move(std::regex_replace(str, r, std::to_string(line).c_str()));
        }
    }
} // logger