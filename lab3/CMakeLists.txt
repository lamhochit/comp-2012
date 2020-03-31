cmake_minimum_required(VERSION 3.15)
project(lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab3 Coronavirus.cpp
        Coronavirus.h
        Doctor.cpp
        Doctor.h
        main.cpp
        Norovirus.cpp
        Norovirus.h
        Patient.cpp
        Patient.h
        Patient_with_coronavirus.cpp
        Patient_with_coronavirus.h
        Patient_with_norovirus.cpp
        Patient_with_norovirus.h
        Person.cpp
        Person.h
        Virus.cpp
        Virus.h)