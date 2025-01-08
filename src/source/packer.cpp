//
// Created by l1Akr on 24-8-11.
//

#include "packer.h"

/**
 * 日志：%message
 * 函数名：%func
 * 代码行：%line
 * 日志等级：%level
 * 代码路径：%filepath
 * 时间： %s {%Y-%m-%d %H:%M:%S}
 * 标签： %tag
 */
const char* packer::RootFormatStr               = "[%level] [%tag] [%s {%Y-%m-%d %H:%M:%S}] %filepath:%line (%func): %message";
const packer::level packer::RootLevel           = packer::level::Info;