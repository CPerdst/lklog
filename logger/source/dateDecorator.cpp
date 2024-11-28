//
// Created by leakerma on 8/9/2024.
//

#include "dateDecorator.h"
#include "regex"
#include "iostream"

namespace logger {
    void dateDecorator::format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) {
        std::regex r("%s[' ']*(\\{(.*?)\\})?");
        std::smatch match;
        if(std::regex_search(str, match, r)){
            auto it = events.find("time");
            if(it == events.end() || !std::holds_alternative<int>(it->second)) return;
            const auto& value = it->second;
            time_t tt = std::get<int>(value);
            tm* t = localtime(&tt);
            char tmp[80] = {};
            std::strftime(tmp, sizeof(tmp), match[2].str().c_str(), t);
//            std::cout << tmp << std::endl;
            str = std::move(std::regex_replace(str, r, tmp));
        }
    }
} // logger