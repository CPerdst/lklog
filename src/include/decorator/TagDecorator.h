//
// Created by lbyeagleyun on 2025/1/8.
//

#ifndef LKLOG_TAGDECORATOR_H
#define LKLOG_TAGDECORATOR_H

#include "Decorator.h"
#include "tools.h"

namespace logger::decorator {

    class DLL_API TagDecorator : public Decorator{
    public:
        TagDecorator(): Decorator(){};
        ~TagDecorator() override = default;

        void format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
    };

} // logger

#endif //LKLOG_TAGDECORATOR_H
