cmake_minimum_required(VERSION 3.10)
project(LAB2_2 C)

set(CMAKE_C_STANDARD 11)

enable_testing()

include_directories(include)

add_executable(lab2
    main.c
    source/lab2.c
)
target_link_libraries(lab2 m)


add_executable(lab2_tests
    source/lab2.c
    tests/tests.c
)

target_include_directories(lab2_tests PRIVATE include)

target_link_libraries(lab2_tests m)

add_test(NAME unit_tests COMMAND lab2_tests)