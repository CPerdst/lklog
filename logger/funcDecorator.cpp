//
// Created by l1Akr on 24-8-21.
//

#include "funcDecorator.h"
#include "regex"

namespace logger {
    void funcDecorator::format(std::map<std::string, std::variant<int, std::string, std::thread::id>> &events) {
        std::regex r("(%func)");
        std::smatch match;
        if(std::regex_search(str, match, r)){
            auto it = events.find("func");
            if(it == events.end() || !std::holds_alternative<std::string>(it->second)) return;
            const auto& value = it->second;
            std::string tmp = std::get<std::string>(value);
            str = std::move(std::regex_replace(str, r, tmp));
        }
    }
} // logger