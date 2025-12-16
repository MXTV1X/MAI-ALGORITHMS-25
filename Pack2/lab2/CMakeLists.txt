cmake_minimum_required(VERSION 3.10)
project(LAB2_2 C) # Указал, что это C-проект

set(CMAKE_C_STANDARD 11)

# Активация модуля CTest для возможности запуска тестов
enable_testing()

include_directories(include)

# 1. Сборка основного исполняемого файла
add_executable(lab2
    main.c
    source/lab2.c
)
target_link_libraries(lab2 m)

# --------------------------
# 2. БЛОК ТЕСТИРОВАНИЯ
# --------------------------

# Создание исполняемого файла для тестов.
# Он включает тестируемый исходник (source/lab2.c) и сами тесты (tests/tests.c)
add_executable(lab2_tests
    source/lab2.c
    tests/tests.c
)

# Установка пути к заголовочным файлам для тестов
target_include_directories(lab2_tests PRIVATE include)

# Связывание с библиотекой 'm' (если она нужна для тестируемой функции)
target_link_libraries(lab2_tests m)


# Регистрация исполняемого файла как теста для CTest
# CTest будет запускать 'lab2_tests' при вызове 'ctest'
add_test(NAME unit_tests COMMAND lab2_tests)