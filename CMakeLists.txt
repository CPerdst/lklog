cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # 静态库输出路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # 动态库输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) # 二进制文件输出路径

set (CRT_BUILD_TYPE "static")

project(lklog)

file(GLOB LKLOG_SOURCE "src/source/*.cpp")

if ("${CRT_BUILD_TYPE}" STREQUAL "static")
    add_library(lklog STATIC ${LKLOG_SOURCE})
    if (MSVC)
        target_compile_options(lklog PRIVATE /MT)
    endif ()
elseif ("${CRT_BUILD_TYPE}" STREQUAL "dynamic")
    add_library(lklog SHARED ${LKLOG_SOURCE})
    if (MSVC)
        target_compile_options(lklog PRIVATE /MD)
    endif ()
else ()
    message(FATAL_ERROR "Macro CRT_BUILD_TYPE: ${CRT_BUILD_TYPE} is invalid")
endif ()

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