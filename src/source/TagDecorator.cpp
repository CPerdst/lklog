//
// Created by lbyeagleyun on 2025/1/8.
//

#include "decorator/TagDecorator.h"
#include "regex"

namespace logger {
    void decorator::TagDecorator::format(std::map<std::string, std::variant<int, std::string, std::thread::id>> &events) {
        std::regex r("(%tag)");
        std::smatch match;
        if(std::regex_search(str, match, r)){
            auto it = events.find("tag");
            if(it == events.end() || !std::holds_alternative<std::string>(it->second)) return;
            const auto& value = it->second;
            std::string tag = std::get<std::string>(value);
            str = std::move(std::regex_replace(str, r, tag.c_str()));
        }
    }
} // logger