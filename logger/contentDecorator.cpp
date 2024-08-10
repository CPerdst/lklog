//
// Created by l1Akr on 24-8-11.
//

#include "contentDecorator.h"
#include "regex"

namespace logger {
    void contentDecorator::format(std::map<std::string, std::variant<int, std::string, std::thread::id>> &events) {
        std::regex r("(%msg|%message)");
        std::smatch match;
        if(std::regex_search(str, match, r)){
            auto it = events.find("content");
            if(it == events.end() || !std::holds_alternative<std::string>(it->second)) return;
            const auto& value = it->second;
            std::string message = std::get<std::string>(value);
            str = std::move(std::regex_replace(str, r, message));
        }
    }
} // logger