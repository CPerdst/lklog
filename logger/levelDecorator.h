//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_LEVELDECORATOR_H
#define LKLOG_LEVELDECORATOR_H

#include "decorator.h"

namespace logger {

    class levelDecorator :public decorator{
    public:
        levelDecorator():decorator(){};
        ~levelDecorator() override = default;

        void format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
    };

} // logger

#endif //LKLOG_LEVELDECORATOR_H
