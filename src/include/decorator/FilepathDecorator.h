//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_FILEPATHDECORATOR_H
#define LKLOG_FILEPATHDECORATOR_H

#include "Decorator.h"
#include "tools.h"

namespace logger::decorator {

    class DLL_API FilepathDecorator: public Decorator {
    public:
        FilepathDecorator(): Decorator(){};
        ~FilepathDecorator() override = default;

        void format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
    };

} // logger

#endif //LKLOG_FILEPATHDECORATOR_H
