//
// Created by leakerma on 8/9/2024.
//

#include "decorator.h"

namespace logger {

    std::string decorator::operation(std::string& event) {
        str = std::move(ptr->operation(event));
        format();
        return std::move(str);
    }

    void decorator::setPtr(baseDecorator *p) {
        if(p) ptr = p;
    }
} // logger