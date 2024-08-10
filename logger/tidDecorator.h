//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_TIDDECORATOR_H
#define LKLOG_TIDDECORATOR_H

#include "decorator.h"

namespace logger {

    class tidDecorator :public decorator{
    public:
        tidDecorator():decorator(){};
        ~tidDecorator() override = default;

        void format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
    };

} // logger

#endif //LKLOG_TIDDECORATOR_H
