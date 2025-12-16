#ifndef _LAB1_8
#define _LAB1_8

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Константы
#define MAX_BASE 36
#define MAX_TOKEN_LEN 256
#define MAX_OUTPUT_LEN 65 // Достаточно для long long в base 2

// Коды статуса
typedef enum {
    SUCCESS = 0,
    INCORRECT_INPUT,
    INCORRECT_BASE
} BadType;

// Преобразует символ (0-9, A-Z) в его численное значение (0-35).
int char_to_value(char c);

// Преобразует численное значение (0-35) в символ ('0'-'9', 'A'-'Z').
char value_to_char(int value);

// Проверяет корректность строки числа s для заданного основания base.
BadType validate_number(const char *s, int base);

// Переводит число из заданного основания в десятичное (long long).
long long convert_to_decimal(const char *s, int base);

// Переводит десятичное число (long long) в строку в заданном основании.
void convert_from_decimal(long long n, int base, char *output_s);

// Нормализует строку: удаляет ведущие нули (но не знак).
void normalize_string(const char *input_s, char *output_s);

#endif