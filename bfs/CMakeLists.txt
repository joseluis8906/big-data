cmake_minimum_required(VERSION 2.6)
project(bfs)

set(bfs_VERSION_MAJOR 1)
set(bfs_VERSION_MINOR 0)

include_directories(include src)
file(GLOB SOURCES "src/*.cpp")

add_executable(bfs ${SOURCES})
