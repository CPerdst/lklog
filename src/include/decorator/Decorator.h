//
// Created by leakerma on 8/9/2024.
//

#ifndef LOGGER_DECORATOR_H
#define LOGGER_DECORATOR_H

#include "decorator/BaseDecorator.h"
#include "memory"
#include "tools.h"

namespace logger::decorator {

    class DLL_API Decorator: public BaseDecorator{
    public:
        Decorator(): BaseDecorator(){};
        ~Decorator() override = default;
        Decorator(const Decorator&) = delete;
        Decorator& operator=(const Decorator&) = delete;
        Decorator(Decorator&&) noexcept = default;
        Decorator& operator=(Decorator&&) = default;
        std::string operation(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) override;
        virtual void format(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) = 0;
        void setPtr(BaseDecorator*);
    protected:
        std::string str;
    private:
//        std::weak_ptr<BaseDecorator> ptr;
        BaseDecorator* ptr{};
    };

} // logger

#endif //LOGGER_DECORATOR_H
