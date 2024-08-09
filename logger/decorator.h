//
// Created by leakerma on 8/9/2024.
//

#ifndef LOGGER_DECORATOR_H
#define LOGGER_DECORATOR_H

#include "baseDecorator.h"
#include "memory"

namespace logger {

    class decorator: public baseDecorator{
    public:
        decorator():baseDecorator(){};
        ~decorator() override = default;
        decorator(const decorator&) = delete;
        decorator& operator=(const decorator&) = delete;
        decorator(decorator&&) noexcept = default;
        decorator& operator=(decorator&&) = default;
        std::string operation(std::string& event) override;
        virtual void format() = 0;
        void setPtr(baseDecorator*);
    protected:
        std::string str;
    private:
        std::unique_ptr<baseDecorator> ptr;
    };

} // logger

#endif //LOGGER_DECORATOR_H
