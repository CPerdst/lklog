//
// Created by l1Akr on 24-8-10.
//

#include "filepathDecorator.h"
#include "regex"
#include "iostream"

namespace logger {
    void filepathDecorator::format(std::map<std::string, std::variant<int, std::string, std::thread::id>> &events) {
        std::regex r("(%path|%filepath)");
        std::smatch match;
        if(std::regex_search(str, match, r)){
            auto it = events.find("path");
            if(it == events.end() || !std::holds_alternative<std::string>(it->second)) return;
            const auto& tmp = std::get<std::string>(it->second);
            str = std::move(std::regex_replace(str, r, tmp.c_str()));
        }
    }
} // logger