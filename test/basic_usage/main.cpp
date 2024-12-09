//
// Created by l1Akr on 2024/12/3.
//
#include "iostream"
#include "eventCapturer.h"

int main() {
    /**
     * should see
     * "[Info] [2024-12-03 19:06:56] path/to/main.cpp:12 (main): hello world."
     */
    RootInfo() << "hello world.";
}