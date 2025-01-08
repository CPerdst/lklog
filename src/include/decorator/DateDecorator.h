//
// Created by leakerma on 8/9/2024.
//

#ifndef LOGGER_DATEDECORATOR_H
#define LOGGER_DATEDECORATOR_H

#include "Decorator.h"
#include "tools.h"

namespace logger::decorator {

    class DLL_API DateDecorator : public Decorator{
    public:
        DateDecorator(): Decorator(){};
        ~DateDecorator() override = default;

        void format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
    };

} // logger

#endif //LOGGER_DATEDECORATOR_H
