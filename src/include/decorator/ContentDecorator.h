//
// Created by l1Akr on 24-8-11.
//

#ifndef LKLOG_CONTENTDECORATOR_H
#define LKLOG_CONTENTDECORATOR_H

#include "Decorator.h"
#include "tools.h"

namespace logger::decorator {

    class DLL_API ContentDecorator : public Decorator{
    public:
        ContentDecorator(): Decorator(){};
        ~ContentDecorator() override = default;

        void format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
    };

} // logger

#endif //LKLOG_CONTENTDECORATOR_H
