//
// Created by leakerma on 8/9/2024.
//

#include "formator.h"
#include "iostream"

namespace logger {
    formator::formator(): BaseDecorator(){
        // 添加装饰器
        auto tmp = std::make_unique<decorator::DateDecorator>();
        tmp->setPtr(this);
        auto tmp1 = std::make_unique<decorator::FilepathDecorator>();
        tmp1->setPtr(tmp.get());
        auto tmp2 = std::make_unique<decorator::LineDecorator>();
        tmp2->setPtr(tmp1.get());
        auto tmp3 = std::make_unique<decorator::LevelDecorator>();
        tmp3->setPtr(tmp2.get());
        auto tmp4 = std::make_unique<decorator::TidDecorator>();
        tmp4->setPtr(tmp3.get());
        auto tmp5 = std::make_unique<decorator::ContentDecorator>();
        tmp5->setPtr(tmp4.get());
        auto tmp6 = std::make_unique<decorator::FuncDecorator>();
        tmp6->setPtr(tmp5.get());
        auto tmp7 = std::make_unique<decorator::TagDecorator>();
        tmp7->setPtr(tmp6.get());
        vec.push_back(std::move(tmp));
        vec.push_back(std::move(tmp1));
        vec.push_back(std::move(tmp2));
        vec.push_back(std::move(tmp3));
        vec.push_back(std::move(tmp4));
        vec.push_back(std::move(tmp5));
        vec.push_back(std::move(tmp6));
        vec.push_back(std::move(tmp7));
    };

    std::string formator::operation(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) {
        return strs;
    }

    std::string formator::format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) {
        std::string r = vec.back()->operation(events);
        return std::move(r);
    }

    void formator::setStr(std::string s) {
        std::string tmp = std::move(s);
//        std::cout << tmp << std::endl;
//        strs.append("asd");
//        std::cout << strs << std::endl;
        strs = std::move(tmp);
    }

    std::string formator::getStr() {
        return strs;
    }
} // logger