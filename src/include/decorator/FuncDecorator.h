//
// Created by l1Akr on 24-8-21.
//

#ifndef LKLOG_FUNCDECORATOR_H
#define LKLOG_FUNCDECORATOR_H

#include "Decorator.h"
#include "tools.h"

namespace logger::decorator {

    class DLL_API FuncDecorator : public Decorator{
    public:
        FuncDecorator(): Decorator(){};
        ~FuncDecorator() override = default;

        void format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
    };

} // logger

#endif //LKLOG_FUNCDECORATOR_H
