//
// Created by leakerma on 8/9/2024.
//

#include "decorator/Decorator.h"

namespace logger {

    std::string decorator::Decorator::operation(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) {
        str = std::move(ptr->operation(events));
        format(events);
        return std::move(str);
    }

    void decorator::Decorator::setPtr(decorator::BaseDecorator *p) {
        if(p) ptr = p;
    }
} // logger