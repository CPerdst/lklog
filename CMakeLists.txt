cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # 静态库输出路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # 动态库输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) # 二进制文件输出路径

project(lklog)

file(GLOB LKLOG_SOURCE "src/source/*.cpp")

add_library(lklog SHARED ${LKLOG_SOURCE})

if (WIN32)
    target_compile_definitions(lklog PRIVATE EXPORTING_DLL)
endif ()

target_include_directories(lklog PUBLIC "src/include")

# ----------------------
# 编译测试样例
# ----------------------

if(EXAMPLE_BUILD)
    add_subdirectory(example)
endif()