//
// Created by l1Akr on 24-8-10.
//

#ifndef LKLOG_PACKER_H
#define LKLOG_PACKER_H

#include "tools.h"

[[maybe_unused]] static const char* LevelToName[] = {"Trace","Debug", "Info", "Notice", "Warn", "Error", "Fatal"};

/**
 * 日志：%message
 * 函数名：%func
 * 代码行：%line
 * 日志等级：%level
 * 代码路径：%filepath
 * 时间： %s {%Y-%m-%d %H:%M:%S}
 * 标签： %tag
 */

class DLL_API packer {
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
    static const char* RootFormatStr;
    static const packer::level RootLevel;
};


#endif //LKLOG_PACKER_H
