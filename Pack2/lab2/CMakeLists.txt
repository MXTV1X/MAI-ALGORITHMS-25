cmake_minimum_required(VERSION 3.10)
project(LAB1)

set(CMAKE_C_STANDARD 11)


include_directories(include)

add_executable(lab2
    main.c
    ../source/lab2.c
)