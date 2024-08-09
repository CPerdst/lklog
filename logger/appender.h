//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_APPENDER_H
#define LKLOG_APPENDER_H

#include "string"

namespace logger {

    class appender {
    public:
        appender() = default;
        virtual ~appender() = default;
        virtual void logOut(std::string log) = 0;
    };

} // logger

#endif //LKLOG_APPENDER_H
