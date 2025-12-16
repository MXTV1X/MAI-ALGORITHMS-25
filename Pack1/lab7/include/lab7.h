#ifndef _LAB1_7
#define _LAB1_7

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    SUCCESS,
    INCORRECT_INPUT,
    INCORRECT_EPS
} BadType;

#include <stdlib.h>

#define MAX_BASE 36
#define MAX_TOKEN_LEN 256


// Преобразует символ (0-9, A-Z) в его численное значение (0-35).
int char_to_value(char c);

// Находит минимальное основание системы счисления для заданной строки.
int find_min_base(const char *s);

// Переводит число из заданного основания в десятичное (long long).
long long convert_to_decimal(const char *s, int base);

// Нормализует строку: переводит в верхний регистр и удаляет ведущие нули.
void normalize_number(const char *input_s, char *output_s);

#endif