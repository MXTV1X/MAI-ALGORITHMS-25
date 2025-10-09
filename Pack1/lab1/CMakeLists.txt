cmake_minimum_required(VERSION 3.10)
project(LAB1)

set(CMAKE_C_STANDARD 11)


include_directories(include)

add_executable(lab1
    main.c
    ../source/lab1.c
)