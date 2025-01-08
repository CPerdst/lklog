//
// Created by zwj1 on 24-12-4.
//

#include "EventCapturer.h"

/**
 * 格式化字符串
 * 日志：%message
 * 函数名：%func
 * 代码行：%line
 * 日志等级：%level
 * 代码路径：%filepath
 * 时间： %s {%Y-%m-%d %H:%M:%S}
 * 默认： [%level] [%s {%Y-%m-%d %H:%M:%S}] %filepath:%line (%func): %message
 */

inline void initLogger() {
    logger::logger::Root()->setLogFormater("[%level] [%s {%Y-%m-%d %H-%M-%S}]: %message\n");
}

int main() {
    initLogger();
    // 自动换行
    RootInfo() << "Hello World.";
}