cmake_minimum_required(VERSION 3.27)
project(CPP_DSA)

set(CMAKE_CXX_STANDARD 20)

include_directories(headers)

add_executable(CPP_DSA
        src/main.cpp
        src/LinkedList.cpp
        headers/LinkedList.h
        src/Stack.cpp
        headers/Stack.h
        src/Queue.cpp
        headers/Queue.h
)
