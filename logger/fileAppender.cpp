//
// Created by l1Akr on 24-8-10.
//

#include "fileAppender.h"

namespace logger {
    void fileAppender::open(std::string path) {
        this->path = std::move(path);
        if(ofs.is_open())
            ofs.close();
        // 以追加模式打开文件，默认是std::ios::trunc模式（截断模式，打开文件会自动清空）
        ofs.open(this->path, std::ios::app);
    }

    void fileAppender::logOut(std::string log) {
        if(ofs.is_open())
            ofs << log << std::flush;
    }

    void fileAppender::logOut(std::string log, std::function<void (std::string &)> console_appender_callback)
    {
        if(ofs.is_open())
            ofs << log << std::flush;
    }
} // logger
