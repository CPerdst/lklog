//
// Created by leakerma on 8/9/2024.
//

#ifndef LOGGER_FORMATOR_H
#define LOGGER_FORMATOR_H

#include "vector"
#include "baseDecorator.h"
#include "dateDecorator.h"
#include "lineDecorator.h"
#include "levelDecorator.h"
#include "tidDecorator.h"
#include "funcDecorator.h"
#include "contentDecorator.h"
#include "filepathDecorator.h"
#include "map"
#include "variant"
#include "thread"

namespace logger {

    class formator: public baseDecorator{
    public:
        formator(): baseDecorator(){
            // 添加装饰器
            auto tmp = std::make_unique<dateDecorator>();
            tmp->setPtr(this);
            auto tmp1 = std::make_unique<filepathDecorator>();
            tmp1->setPtr(tmp.get());
            auto tmp2 = std::make_unique<lineDecorator>();
            tmp2->setPtr(tmp1.get());
            auto tmp3 = std::make_unique<levelDecorator>();
            tmp3->setPtr(tmp2.get());
            auto tmp4 = std::make_unique<tidDecorator>();
            tmp4->setPtr(tmp3.get());
            auto tmp5 = std::make_unique<contentDecorator>();
            tmp5->setPtr(tmp4.get());
            auto tmp6 = std::make_unique<funcDecorator>();
            tmp6->setPtr(tmp5.get());
            vec.push_back(std::move(tmp));
            vec.push_back(std::move(tmp1));
            vec.push_back(std::move(tmp2));
            vec.push_back(std::move(tmp3));
            vec.push_back(std::move(tmp4));
            vec.push_back(std::move(tmp5));
            vec.push_back(std::move(tmp6));
        };
        ~formator() override = default;
        std::string operation(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
        std::string format(std::map<std::string, std::variant<int, std::string, std::thread::id>>&);
        void setStr(std::string);
        std::string getStr();
    private:
        std::string strs;
        std::vector<std::unique_ptr<baseDecorator>> vec;
    };

} // logger

#endif //LOGGER_FORMATOR_H
