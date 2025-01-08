//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_APPENDER_H
#define LKLOG_APPENDER_H

#include "string"
#include "functional"
#include "tools.h"

namespace logger {

    class DLL_API Appender {
    public:
        Appender() = default;
        virtual ~Appender() = default;
        virtual void logOut(std::string log) = 0;
        virtual void logOut(std::string log, std::function<void(std::string&)> console_appender_callback) = 0;
    };

} // logger

#endif //LKLOG_APPENDER_H
