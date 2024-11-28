//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_CONSOLEAPPENDER_H
#define LKLOG_CONSOLEAPPENDER_H

#include "appender.h"

namespace logger {

    class consoleAppender : public appender{
    public:
        consoleAppender() = default;
        void logOut(std::string log) override;
        void logOut(std::string log, std::function<void(std::string&)> console_appender_callback) override;
    };

} // logger

#endif //LKLOG_CONSOLEAPPENDER_H
