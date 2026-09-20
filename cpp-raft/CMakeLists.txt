cmake_minimum_required(VERSION 3.20)

project(raft_node)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(raft_node
    src/main.cpp
    src/RaftNode.cpp
)

target_include_directories(raft_node PRIVATE include)