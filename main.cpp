#include "iostream"
#include "vector"
#include "logger/formator.h"
#include "logger/fileAppender.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    logger::formator f{};
    f.setStr(std::string("asd"));
    f.format();
    std::cout << f.getStr() << std::endl;
    // 测试fileAppender是否可以移动
    {
        std::vector<std::unique_ptr<logger::fileAppender>> vec;
        for(int i = 0; i < 10; i++){
            auto tmp = std::make_unique<logger::fileAppender>();
            tmp->open(std::string("./test") + std::to_string(i) + std::string(".txt"));
            vec.push_back(std::move(tmp));
        }
        // 尝试输出内容
        for(auto ite = vec.begin(); ite != vec.end(); ite++){
            (*(*ite)).logOut("nihaoasd\n");
        }
        std::cout << "current dir path: ";
        std::system("echo %cd%");
    }


    return 0;
}
