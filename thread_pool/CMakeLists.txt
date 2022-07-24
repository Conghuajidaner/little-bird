cmake_minimum_required (VERSION 2.6)

project(Thread_pool)

include_directories(include)

add_executable(Thread_Pool src/main.cpp src/thread_pool.cpp)
