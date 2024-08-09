#include "iostream"
#include "vector"
#include "logger/packer.h"
#include "logger/formator.h"
#include "logger/fileAppender.h"
#include "logger/logger.h"
#include "logger/eventCapturer.h"

int main() {
    // 测试fileAppender是否可以移动
    if(packer::DebugFileAppender)
    {
        std::vector<std::unique_ptr<logger::fileAppender>> vec;
        for(int i = 0; i < 10; i++){
            auto tmp = std::make_unique<logger::fileAppender>();
            tmp->open(std::string("./test") + std::to_string(i) + std::string(".txt"));
            vec.push_back(std::move(tmp));
        }
        // 尝试输出内容
        for(const auto& ite : vec){
            ite->logOut(std::string("helloworld\n"));
        }
        std::cout << "current dir path: " << std::flush;
        std::system("echo %cd%");
    }
    // 测试logger是否正常
    if(packer::DebugLogger)
    {
        // 创建 logger 对象，并初始化
        logger::logger log{};
        log.logToConsole();
        log.logToFile("./test.txt");
        log.setLogFormater(std::string("%s {%Y}\n"));
        // 创建 event 对象
        std::map<std::string, std::variant<int, std::string, std::thread::id>> events;
        log.logOut(events);
    }
    // 测试eventCapturer是否正常
    if(packer::DebugEventCapturer)
    {
        logger::logger log{};
        log.logToConsole();
        log.setLogFormater(std::string("%s {%Y}\n"));
        log.setLevel(packer::Debug);
        logger::eventCapturer(__FILE__, __LINE__, std::this_thread::get_id(), packer::Debug, &log).Oss() << "nihao";
    }

    return 0;
}
