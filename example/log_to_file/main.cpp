//
// Created by zwj1 on 24-12-4.
//

#include "EventCapturer.h"

inline void initLogger(std::string& path) {
    logger::logger::Root()->logToFile(path);
}

int main(int argc, char* argv[]){
    if(argc == 1){
        std::string path("./log.txt");
        initLogger(path);
        RootInfo() << "This message will be filled in " << path << "." << std::endl;
    }else if(argc == 2){
        std::string path(argv[1]);
        initLogger(path);
        if(!path.empty())
            RootInfo() << "This message will be filled in " << path << "." << std::endl;
    }
}