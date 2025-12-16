cmake_minimum_required(VERSION 3.10)
project(LAB1_5)

set(CMAKE_C_STANDARD 11)


include_directories(include)

add_executable(lab5
    main.c
    source/lab5.c
)

target_link_libraries(lab5 m)