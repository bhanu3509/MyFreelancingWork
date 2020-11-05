cmake_minimum_required(VERSION 3.17)
project(DEQUE)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Array)
include_directories(LinkedList)

add_executable(DEQUE
        LinkedList/DequeADTList.cpp
        LinkedList/DequeADTList.h
        Array/DequeADTArray.cpp
        Array/DequeADTArray.h
        )
