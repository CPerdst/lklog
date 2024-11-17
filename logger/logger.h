//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_LOGGER_H
#define LKLOG_LOGGER_H

#include "map"
#include "string"
#include "vector"
#include "mutex"
#include "variant"
#include "thread"
#include "fileAppender.h"
#include "consoleAppender.h"
#include "formator.h"
#include "packer.h"

namespace logger {

    class logger {
    public:
        static std::function<void(std::string&)> g_console_appender_callback;

        logger() = default;
        ~logger() = default;
        void logOut(std::map<std::string, std::variant<int, std::string, std::thread::id>>&);
        void logToFile(std::string path);
        void logToConsole();
        void setLogFormater(std::string formaterStr);
        void setLevel(packer::level);
        void setConsoleCallback(std::function<void(std::string&)> callback);
        packer::level getLevel();
        static logger* Root();
        static logger* root;
        static std::mutex* mtx;
    private:
        std::vector<std::shared_ptr<fileAppender>> mFileAppenders;
        std::shared_ptr<consoleAppender> mConsoleAppender;
        std::shared_ptr<formator> mFormater;
        packer::level mLevel;
    };

} // logger

#endif //LKLOG_LOGGER_H
