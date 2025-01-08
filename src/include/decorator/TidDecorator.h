//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_TIDDECORATOR_H
#define LKLOG_TIDDECORATOR_H

#include "Decorator.h"
#include "tools.h"

namespace logger::decorator {

    class DLL_API TidDecorator : public Decorator{
    public:
        TidDecorator(): Decorator(){};
        ~TidDecorator() override = default;

        void format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
    };

} // logger

#endif //LKLOG_TIDDECORATOR_H
