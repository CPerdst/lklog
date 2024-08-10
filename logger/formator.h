//
// Created by leakerma on 8/9/2024.
//

#ifndef LOGGER_FORMATOR_H
#define LOGGER_FORMATOR_H

#include "vector"
#include "baseDecorator.h"
#include "dateDecorator.h"
#include "lineDecorator.h"
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
            vec.push_back(std::move(tmp));
            vec.push_back(std::move(tmp1));
            vec.push_back(std::move(tmp2));
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
