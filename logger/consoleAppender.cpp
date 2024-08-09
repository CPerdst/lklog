//
// Created by l1Akr on 24-8-10.
//

#include "consoleAppender.h"
#include "iostream"

namespace logger {
    void consoleAppender::logOut(std::string log) {
        if(!log.empty()) std::cout << log << std::endl;
    }
} // logger