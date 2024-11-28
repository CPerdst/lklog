//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_FILEPATHDECORATOR_H
#define LKLOG_FILEPATHDECORATOR_H

#include "decorator.h"

namespace logger {

    class filepathDecorator:public decorator {
    public:
        filepathDecorator():decorator(){};
        ~filepathDecorator() override = default;

        void format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
    };

} // logger

#endif //LKLOG_FILEPATHDECORATOR_H
