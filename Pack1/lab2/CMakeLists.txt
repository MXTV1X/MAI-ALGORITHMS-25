cmake_minimum_required(VERSION 3.10)
project(LAB1_2)

set(CMAKE_C_STANDARD 11)


include_directories(include)

add_executable(lab2
    main.c
    source/lab2.c
)

target_link_libraries(lab2 m)