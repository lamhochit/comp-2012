cmake_minimum_required(VERSION 3.16)
project(lab6)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab6 main.cpp
        Customer.cpp
        Customer.h
        Invoice.cpp
        Invoice.h
        main.cpp
        Person.cpp
        Person.h
        Product.cpp
        Product.h
        Salesman.cpp
        Salesman.h)