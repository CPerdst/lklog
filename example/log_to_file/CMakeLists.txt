set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/example)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/example)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB EXAMPLE_LOG_TO_CONSOLE_SOURCE main.cpp)

add_executable(example_log_to_file ${EXAMPLE_LOG_TO_CONSOLE_SOURCE})

target_include_directories(example_log_to_file PRIVATE ../../src/include)

target_link_directories(example_log_to_file PRIVATE ${CMAKE_BINARY_DIR}/lib)

target_link_libraries(example_log_to_file PRIVATE lklog)

message(STATUS "log_to_console has built in " ${CMAKE_BINARY_DIR} "/bin")