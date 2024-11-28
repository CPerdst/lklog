//
// Created by l1Akr on 24-8-10.
//

#include "logger.h"
#include "packer.h"
#include "iostream"



namespace logger {

    std::function<void(std::string&)> logger::g_console_appender_callback = nullptr;

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
        if(mConsoleAppender.get()) {
            if(!g_console_appender_callback)
                mConsoleAppender->logOut(s);
            else
                mConsoleAppender->logOut(s, g_console_appender_callback);
        }
        // 通过 file 输出
        for(auto ite = mFileAppenders.begin(); ite != mFileAppenders.end(); ite++){
            (*(*ite)).logOut(s);
        }
    }

    void logger::setLevel(packer::level level) {
        mLevel = level;
    }

    void logger::setConsoleCallback(std::function<void (std::string &)> callback)
    {
        g_console_appender_callback = std::move(callback);
    }

    packer::level logger::getLevel() {
        return mLevel;
    }

    logger *logger::Root() {
        if(!root){
            auto tmp = new logger();
            tmp->logToConsole();
            tmp->setLogFormater(std::string(packer::RootFormatStr));
            tmp->setLevel(packer::RootLevel);
            root = tmp;
            tmp = nullptr;
            mtx = new std::mutex{};
        }
        return root;
    }

    logger* logger::root = nullptr;
    std::mutex* logger::mtx = nullptr;

} // logger
