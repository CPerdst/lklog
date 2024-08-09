//
// Created by leakerma on 8/9/2024.
//

#ifndef LOGGER_FORMATOR_H
#define LOGGER_FORMATOR_H

#include "vector"
#include "baseDecorator.h"
#include "dateDecorator.h"
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
            auto tmp1 = std::make_unique<dateDecorator>();
            tmp1->setPtr(tmp.get());
            vec.push_back(std::move(tmp));
            vec.push_back(std::move(tmp1));
        };
        ~formator() override = default;
        std::string operation(std::string& events) override;
        std::string format(std::map<std::string, std::variant<int, std::string, std::thread::id>>&);
        void setStr(std::string);
        std::string getStr();
    private:
        std::string strs;
        std::vector<std::unique_ptr<baseDecorator>> vec;
    };

} // logger

#endif //LOGGER_FORMATOR_H
