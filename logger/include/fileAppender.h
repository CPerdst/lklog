//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_FILEAPPENDER_H
#define LKLOG_FILEAPPENDER_H

#include "appender.h"
#include "fstream"

namespace logger {

    class fileAppender : public appender{
    public:
        fileAppender() = default;
        ~fileAppender() override = default;
        fileAppender(const fileAppender&) = delete;
        fileAppender& operator=(const fileAppender&) =delete;
        fileAppender(fileAppender&&) noexcept = default;
        fileAppender& operator=(fileAppender&&) noexcept = default;
        void logOut(std::string log) override;
        void logOut(std::string log, std::function<void(std::string&)> console_appender_callback) override;
        void open(std::string path);
    private:
        std::ofstream ofs;
        std::string path;
    };

} // logger

#endif //LKLOG_FILEAPPENDER_H
