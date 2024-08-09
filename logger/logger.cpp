//
// Created by l1Akr on 24-8-10.
//

#include "logger.h"
#include "packer.h"

namespace logger {
    void logger::setLogFormater(std::string formaterStr) {
        if(!mFormater.get())
            mFormater = std::make_shared<formator>();
        mFormater->setStr(std::move(formaterStr));
    }

    void logger::logToConsole() {
        if(!mConsoleAppender.get())
            mConsoleAppender = std::make_shared<consoleAppender>();
    }

    void logger::logToFile(std::string path) {
        if(mFileAppenders.size() < packer::MaxFileAppenderCount){
            auto tmp = std::make_shared<fileAppender>();
            tmp->open(std::move(path));
            mFileAppenders.push_back(std::move(tmp));
        }
    }

    void logger::logOut(std::map<std::string, std::variant<int, std::string, std::thread::id>>& events) {
        std::string s = mFormater->format(events);
        // 通过 console 输出
        if(mConsoleAppender.get()) mConsoleAppender->logOut(s);
        // 通过 file 输出
        for(auto ite = mFileAppenders.begin(); ite != mFileAppenders.end(); ite++)
            (*(*ite)).logOut(s);
    }
} // logger