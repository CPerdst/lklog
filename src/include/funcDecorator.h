//
// Created by l1Akr on 24-8-21.
//

#ifndef LKLOG_FUNCDECORATOR_H
#define LKLOG_FUNCDECORATOR_H

#include "decorator.h"
#include "tools.h"

namespace logger {

    class DLL_API funcDecorator :public decorator{
    public:
        funcDecorator():decorator(){};
        ~funcDecorator() override = default;

        void format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
    };

} // logger

#endif //LKLOG_FUNCDECORATOR_H
