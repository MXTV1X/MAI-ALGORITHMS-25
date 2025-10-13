cmake_minimum_required(VERSION 3.10)
project(LAB1_3)

set(CMAKE_C_STANDARD 11)


include_directories(include)

add_executable(lab3
    main.c
    source/lab3.c
)

target_link_libraries(lab3 m)