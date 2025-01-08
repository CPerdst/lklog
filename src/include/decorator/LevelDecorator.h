//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_LEVELDECORATOR_H
#define LKLOG_LEVELDECORATOR_H

#include "Decorator.h"
#include "tools.h"

namespace logger::decorator {

    class DLL_API LevelDecorator : public Decorator{
    public:
        LevelDecorator(): Decorator(){};
        ~LevelDecorator() override = default;

        void format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
    };

} // logger

#endif //LKLOG_LEVELDECORATOR_H
