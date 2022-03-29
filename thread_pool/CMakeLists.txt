cmake_minimum_required(VERSION 3.2)

SET(CMAKE_BUILD_TYPE "Debug")

project(thread_pool)

INCLUDE_DIRECTORIES (
    include
)

aux_source_directory(
    src DIR_SRCS    
)

set ( THREAD_POOL
    ${DIR_SRCS}
)

add_executable(${PROJECT_NAME} ${THREAD_POOL})

target_link_libraries(${PROJECT_NAME} pthread)
