//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_LINEDECORATOR_H
#define LKLOG_LINEDECORATOR_H

#include "Decorator.h"
#include "tools.h"

namespace logger::decorator {

    class DLL_API LineDecorator : public Decorator{
    public:
        LineDecorator(): Decorator(){};
        ~LineDecorator() override = default;

        void format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
    };

} // logger

#endif //LKLOG_LINEDECORATOR_H
