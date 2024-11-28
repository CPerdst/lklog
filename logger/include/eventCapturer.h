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

#define LogWarp(LEVEL, LOGGER)  logger::eventCapturer(__FILE__, __func__, __LINE__, std::this_thread::get_id(), LEVEL, LOGGER).Oss()
#define lkRoot(LEVEL)           LogWarp(LEVEL, logger::logger::Root())
#define RootTrace()             lkRoot(packer::level::Trace)
#define RootDebug()             lkRoot(packer::level::Debug)
#define RootInfo()              lkRoot(packer::level::Info)
#define RootNotice()            lkRoot(packer::level::Notice)
#define RootWarn()              lkRoot(packer::level::Warn)
#define RootError()             lkRoot(packer::level::Error)
#define RootFatal()             lkRoot(packer::level::Fatal)

namespace logger {

    class eventCapturer {
    public:
        eventCapturer(std::string path, std::string func, int line, std::thread::id tid, packer::level level, logger* ptr) :
        mPath(std::move(path)),
        mFunc(std::move(func)),
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
        std::string mFunc;
        int mLine;
        std::thread::id mTid;
        packer::level mLevel;
        time_t mNow;
        logger* mPtr;
        const static time_t BeginTimer;
    };

} // logger

#endif //LKLOG_EVENTCAPTURER_H
