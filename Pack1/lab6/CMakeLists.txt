cmake_minimum_required(VERSION 3.10)
project(LAB1_6)

set(CMAKE_C_STANDARD 11)


include_directories(include)

add_executable(lab6
    main.c
    source/lab6.c
)

target_link_libraries(lab6 m)