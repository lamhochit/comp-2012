cmake_minimum_required(VERSION 3.15)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab4 beverage_store.cpp
        beverage_store.h
        gold_card.cpp
        gold_card.h
        main.cpp
        regular_card.cpp
        regular_card.h
        silver_card.h
        sliver_card.cpp
        vip_lounge.cpp
        vip_lounge.h)