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
#include "tools.h"
#include "sstream"

#define LogWarp(LEVEL, LOGGER, TAG)  logger::EventCapturer(__FILE__, __func__, __LINE__, std::this_thread::get_id(), LEVEL, LOGGER, TAG).Oss()
#define lkRoot(LEVEL, TAG)           LogWarp(LEVEL, logger::logger::Root(), TAG)

#define RootTrace()             lkRoot(packer::level::Trace, "Default")
#define RootDebug()             lkRoot(packer::level::Debug, "Default")
#define RootInfo()              lkRoot(packer::level::Info, "Default")
#define RootNotice()            lkRoot(packer::level::Notice, "Default")
#define RootWarn()              lkRoot(packer::level::Warn, "Default")
#define RootError()             lkRoot(packer::level::Error, "Default")
#define RootFatal()             lkRoot(packer::level::Fatal, "Default")

#define RootTraceWithTag(TAG)             lkRoot(packer::level::Trace, TAG)
#define RootDebugWithTag(TAG)             lkRoot(packer::level::Debug, TAG)
#define RootInfoWithTag(TAG)              lkRoot(packer::level::Info, TAG)
#define RootNoticeWithTag(TAG)            lkRoot(packer::level::Notice, TAG)
#define RootWarnWithTag(TAG)              lkRoot(packer::level::Warn, TAG)
#define RootErrorWithTag(TAG)             lkRoot(packer::level::Error, TAG)
#define RootFatalWithTag(TAG)             lkRoot(packer::level::Fatal, TAG)

namespace logger {

    class DLL_API EventCapturer {
    public:
        EventCapturer(std::string path, std::string func, int line, std::thread::id tid, packer::level level, logger* ptr, std::string const& tag);
        EventCapturer(std::string path, std::string func, int line, std::thread::id tid, packer::level level, logger* ptr, std::string && tag);
        ~EventCapturer();
        EventCapturer(const EventCapturer&) = delete;
        EventCapturer operator=(const EventCapturer&) = delete;
        EventCapturer(EventCapturer&&) noexcept = default;
        EventCapturer& operator=(EventCapturer&&) noexcept = default;
        std::ostringstream& Oss();
    private:
        std::map<std::string, std::variant<int, std::string, std::thread::id>> getEvents();

        std::ostringstream oss;
        std::string mPath;
        std::string mFunc;
        std::string mTag;
        int mLine;
        std::thread::id mTid;
        packer::level mLevel;
        time_t mNow;
        logger* mPtr;
        const static time_t BeginTimer;
    };

} // logger

#endif //LKLOG_EVENTCAPTURER_H
