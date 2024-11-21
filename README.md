# lklog

`lklog` 是一个轻量级、高效的 C++ 日志器，支持 C++17 及以上版本。它提供了便捷的接口，能够打印包含时间、线程 ID、文件路径以及行号的日志信息，帮助开发者更好地调试和维护代码。

## 特性

- **时间戳**：日志信息中自动添加当前时间，方便追踪日志记录的时间点。
- **线程 ID**：支持多线程环境下的日志记录，自动记录线程 ID，方便定位多线程问题。
- **文件路径和行号**：自动记录日志的来源文件路径和代码行号，方便快速定位问题。
- **高效**：经过优化，确保在高性能要求的环境中也能高效运行。
- **自定义格式**：支持通过格式化字符串自定义日志输出格式，满足各种日志记录需求。
- **线程安全**：支持多线程下的同步日志输出

## 安装

你可以将 `lklog` 项目直接包含到你的 C++ 项目中。

## 使用

### 日志器宏基本使用

lklog 共有七中日志等级（Trace、Debug、Info、Notice、Warn、Error、Fatal），使用方法也很简单

只需要使用对应的宏即可

```cpp
#include "eventCapturer.h"

int main(){
    // 七种模式的简单使用
    RootTrace() << "Trace";
    RootDebug() << "Debug";
    RootInfo() << "Info";
    RootNotice() << "Notice";
    RootWarn() << "Warn";
    RootError() << "Error";
    RootFatal() << "Fatal";
}
```

默认日志器等级是Debug

默认日志格式："[%s {%Y-%m-%d %H:%M:%S}] [%level] %filepath:%line (%func): %message\n"

### 更改日志器的默认设置

```cpp
#include "eventCapturer.h"

int main(){
    // 设置日志等级
    logger::logger::Root()->setLevel(packer::Info);
    // 设置日志格式
    logger::logger::Root()->setLogFormater("[%filepath:%line]: %message\n");
    // 设置日志输出到对应的文件
    logger::logger::Root()->logToFile("./test.txt");
}
```

### 格式化字符串：

**日志等级**：%level

**线程ID**：%threadid{prefix_num}

**日志时间**：%s {时间格式}

**文件路径**：%filepath

**文件行号**：%line

事例: [%threadid{4}] [%level] [%s {%Y-%m-%d %H:%M:%S}] %filepath:%line

整体输出: [8eb7] [Debug] [2024-08-11 04:26:20] C:/path/to/project/main.cpp:46

### 克隆仓库

```bash
git clone https://github.com/CPerdst/lklog.git
