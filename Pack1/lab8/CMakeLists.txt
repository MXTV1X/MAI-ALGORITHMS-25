cmake_minimum_required(VERSION 3.10)
project(LAB1_8)

set(CMAKE_C_STANDARD 11)


include_directories(include)

add_executable(lab8
    main.c
    source/lab8.c
)

target_link_libraries(lab8 m)