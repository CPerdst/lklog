//
// Created by zwj1 on 24-12-4.
//

#include "iostream"
#include "functional"
#include "eventCapturer.h"

inline void initLogger() {
    auto callback = [](std::string& message){
        // handle message
        // ...
        // use message
        std::cout << message << std::endl;
    };
    logger::logger::Root()->setConsoleCallback(callback);
}

int main() {
    initLogger();
    RootInfo() << "hello world." << std::endl;
}