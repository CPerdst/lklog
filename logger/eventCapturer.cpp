//
// Created by l1Akr on 24-8-10.
//

#include "eventCapturer.h"

namespace logger {

    const time_t eventCapturer::BeginTimer = time(nullptr);

    std::ostringstream &eventCapturer::Oss() {
        return oss;
    }

    eventCapturer::~eventCapturer() {
        if(mLevel >= mPtr->getLevel()){
            std::lock_guard<std::mutex> lock(*logger::mtx);
            auto tmp = getEvents();
            mPtr->logOut(tmp);
        }
    }

    std::map<std::string, std::variant<int, std::string, std::thread::id>> eventCapturer::getEvents() {
        std::map<std::string, std::variant<int, std::string, std::thread::id>> events{};
        events["path"]      = std::move(mPath);
        events["func"]      = std::move(mFunc);
        events["line"]      = mLine;
        events["tid"]       = mTid;
        events["time"]      = (int)mNow;
        events["level"]     = mLevel;
        events["content"]   = std::move(oss.str());
        return std::move(events);
    }

} // logger