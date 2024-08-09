//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_EVENTCAPTURER_H
#define LKLOG_EVENTCAPTURER_H

#include "string"
#include "thread"
#include "packer.h"
#include "chrono"
#include "logger.h"
#include "sstream"

namespace logger {

    class eventCapturer {
    public:
        eventCapturer(std::string path, int line, std::thread::id tid, packer::level level, logger* ptr) :
        mPath(std::move(path)),
        mLine(line),
        mTid(tid),
        mLevel(level),
        mPtr(ptr)
        {
            mNow = time(nullptr);
        }
        ~eventCapturer();
        eventCapturer(const eventCapturer&) = delete;
        eventCapturer operator=(const eventCapturer&) = delete;
        eventCapturer(eventCapturer&&) noexcept = default;
        eventCapturer& operator=(eventCapturer&&) noexcept = default;
        std::ostringstream& Oss();
    private:
        std::map<std::string, std::variant<int, std::string, std::thread::id>> getEvents();

        std::ostringstream oss;
        std::string mPath;
        int mLine;
        std::thread::id mTid;
        packer::level mLevel;
        time_t mNow;
        logger* mPtr;
        const static time_t BeginTimer;
    };

} // logger

#endif //LKLOG_EVENTCAPTURER_H
