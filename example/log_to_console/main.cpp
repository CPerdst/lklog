//
// Created by zwj1 on 24-12-4.
//

#include "iostream"
#include "eventCapturer.h"

void initLogger(){
    logger::logger::Root()->setLevel(packer::Trace);
}

int main(){
    RootInfo() << "First init logger default level to trace." << std::endl;
    initLogger();
    RootTrace() << "Level Trace Log" << std::endl;
    RootDebug() << "Level Debug Log" << std::endl;
    RootInfo() << "Level Info Log" << std::endl;
    RootNotice() << "Level Notice Log" << std::endl;
    RootWarn() << "Level Warn Log" << std::endl;
    RootError() << "Level Error Log" << std::endl;
    RootFatal() << "Level Fatal Log" << std::endl;
}