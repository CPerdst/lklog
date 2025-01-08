//
// Created by l1Akr on 24-8-10.
//

#include "EventCapturer.h"

namespace logger {

    const time_t EventCapturer::BeginTimer = time(nullptr);

    std::ostringstream &EventCapturer::Oss() {
        return oss;
    }

    EventCapturer::EventCapturer(std::string path, std::string func, int line, std::thread::id tid, packer::level level, logger* ptr, std::string const& tag) :
            mPath(std::move(path)),
            mFunc(std::move(func)),
            mLine(line),
            mTid(tid),
            mLevel(level),
            mPtr(ptr),
            mTag(tag)
    {
        mNow = time(nullptr);
    }
    EventCapturer::EventCapturer(std::string path, std::string func, int line, std::thread::id tid, packer::level level, logger* ptr, std::string && tag) :
            mPath(std::move(path)),
            mFunc(std::move(func)),
            mLine(line),
            mTid(tid),
            mLevel(level),
            mPtr(ptr),
            mTag(std::move(tag))
    {
        mNow = time(nullptr);
    }


    EventCapturer::~EventCapturer() {
        if(mLevel >= mPtr->getLevel()){
            std::lock_guard<std::mutex> lock(*logger::mtx);
            auto tmp = getEvents();
            mPtr->logOut(tmp);
        }
    }

    std::map<std::string, std::variant<int, std::string, std::thread::id>> EventCapturer::getEvents() {
        std::map<std::string, std::variant<int, std::string, std::thread::id>> events{};
        events["path"]      = std::move(mPath);
        events["func"]      = std::move(mFunc);
        events["line"]      = mLine;
        events["tid"]       = mTid;
        events["time"]      = (int)mNow;
        events["level"]     = mLevel;
        events["content"]   = std::move(oss.str());
        events["tag"]       = mTag;
        return std::move(events);
    }

} // logger