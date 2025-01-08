//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_FILEAPPENDER_H
#define LKLOG_FILEAPPENDER_H

#include "Appender.h"
#include "fstream"
#include "tools.h"

namespace logger {

    class DLL_API FileAppender : public Appender{
    public:
        FileAppender() = default;
        ~FileAppender() override = default;
        FileAppender(const FileAppender&) = delete;
        FileAppender& operator=(const FileAppender&) =delete;
        FileAppender(FileAppender&&) noexcept = default;
        FileAppender& operator=(FileAppender&&) noexcept = default;
        void logOut(std::string log) override;
        void logOut(std::string log, std::function<void(std::string&)> console_appender_callback) override;
        void open(std::string path);
    private:
        std::ofstream ofs;
        std::string path;
    };

} // logger

#endif //LKLOG_FILEAPPENDER_H
