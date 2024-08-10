//
// Created by l1Akr on 24-8-11.
//

#ifndef LKLOG_CONTENTDECORATOR_H
#define LKLOG_CONTENTDECORATOR_H

#include "decorator.h"

namespace logger {

    class contentDecorator :public decorator{
    public:
        contentDecorator():decorator(){};
        ~contentDecorator() override = default;

        void format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
    };

} // logger

#endif //LKLOG_CONTENTDECORATOR_H
