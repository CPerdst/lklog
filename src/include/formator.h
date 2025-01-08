//
// Created by leakerma on 8/9/2024.
//

#ifndef LOGGER_FORMATOR_H
#define LOGGER_FORMATOR_H

#include "vector"
#include "decorator/BaseDecorator.h"
#include "decorator/DateDecorator.h"
#include "decorator/LineDecorator.h"
#include "decorator/LevelDecorator.h"
#include "decorator/TidDecorator.h"
#include "decorator/FuncDecorator.h"
#include "decorator/ContentDecorator.h"
#include "decorator/FilepathDecorator.h"
#include "decorator/TagDecorator.h"
#include "map"
#include "variant"
#include "thread"
#include "tools.h"

namespace logger {

    class formator: public decorator::BaseDecorator{
    public:
        formator();
        ~formator() override = default;
        std::string operation(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
        std::string format(std::map<std::string, std::variant<int, std::string, std::thread::id>>&);
        void setStr(std::string);
        std::string getStr();
    private:
        std::string strs;
        std::vector<std::unique_ptr<decorator::BaseDecorator>> vec;
    };

} // logger

#endif //LOGGER_FORMATOR_H
