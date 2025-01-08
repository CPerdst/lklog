//
// Created by l1Akr on 24-8-10.
//

#include "ConsoleAppender.h"
#include "iostream"

namespace logger {
    void ConsoleAppender::logOut(std::string log) {
        if(!log.empty()) {
            std::cout << log << std::flush;
        }
    }

    void ConsoleAppender::logOut(std::string log, std::function<void (std::string &)> console_appender_callback)
    {
        if(!log.empty()){
            if(console_appender_callback){
                console_appender_callback(log);
            }else{
                std::cout << log << std::flush;
            }
        }
    }
} // logger
