//
// Created by leakerma on 8/9/2024.
//

#ifndef LOGGER_BASEDECORATOR_H
#define LOGGER_BASEDECORATOR_H

#include "string"

namespace logger {

    class baseDecorator {
    public:
        baseDecorator() = default;
        virtual ~baseDecorator() = default;
        virtual std::string operation(std::string& event) = 0;
    };

} // logger

#endif //LOGGER_BASEDECORATOR_H
