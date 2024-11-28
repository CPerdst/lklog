//
// Created by l1Akr on 24-8-10.
//

#include "tidDecorator.h"
#include "regex"
#include "iostream"
#include "iomanip"

namespace logger {
    void tidDecorator::format(std::map<std::string, std::variant<int, std::string, std::thread::id>> &events) {
        std::regex r("(%tid|%threadid)(\\{(\\d+)\\})?");
        std::smatch match;
        if(std::regex_search(str, match, r)){
            auto it = events.find("tid");
            if(it == events.end() || !std::holds_alternative<std::thread::id>(it->second)) return;
            std::string size{"8"};
            if(!match[3].str().empty()) {
                if(std::stoi(match[match.size() - 1]) > 15){
                    size = "15";
                }
                else if(std::stoi(match[match.size() - 1]) < 1){
                    size = "1";
                }
                else{
                    size = match[match.size()-1];
                }
            }
            // 首先转变tid为size_t
            const auto& value = it->second;
            auto tmp = std::get<std::thread::id>(value);
            std::hash<std::thread::id> h;
            auto thash = h(tmp);
            // 更具size和thash生成指定长度的字符串
            std::ostringstream oss;
            oss << std::hex << std::setw(16) << std::setfill('0') << thash;
            str = std::move(std::regex_replace(str, r, oss.str().substr(oss.str().size() - std::stoi(size), oss.str().size())));
        }
    }
} // logger