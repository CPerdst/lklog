//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_PACKER_H
#define LKLOG_PACKER_H

class packer {
public:
    const static int MaxFileAppenderCount       = 10;
    const static bool DebugFileAppender         = false;
    const static bool DebugLogger               = false;
    const static bool DebugEventCapturer        = true;
    enum level {
        Trace,
        Debug,
        Info,
        Notice,
        Warn,
        Error,
        Fatal
    };
};


#endif //LKLOG_PACKER_H
