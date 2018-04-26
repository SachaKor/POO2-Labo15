cmake_minimum_required(VERSION 3.8)
project(List)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Hero.cpp
        Hero.h
        List.h
        main.cpp
        Person.cpp
        Person.h)

add_executable(List ${SOURCE_FILES})