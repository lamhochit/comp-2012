cmake_minimum_required(VERSION 3.16)
project(pa3)

set(CMAKE_CXX_STANDARD 14)

add_executable(pa3 hotpot.txt
        infectionAnalyzer.cpp
        infectionAnalyzer.h
        infections1.txt
        infections2.txt
        infections3.txt
        infections4.txt
        main.cpp
        node.h
        tree.h
        treeImplementation.h)