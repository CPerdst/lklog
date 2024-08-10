//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_LINEDECORATOR_H
#define LKLOG_LINEDECORATOR_H

#include "decorator.h"

namespace logger {

    class lineDecorator :public decorator{
    public:
        lineDecorator():decorator(){};
        ~lineDecorator() override = default;

        void format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
    };

} // logger

#endif //LKLOG_LINEDECORATOR_H
