cmake_minimum_required(VERSION 3.10)
project(LAB1_7)

set(CMAKE_C_STANDARD 11)


include_directories(include)

add_executable(lab7
    main.c
    source/lab7.c
)

target_link_libraries(lab7 m)