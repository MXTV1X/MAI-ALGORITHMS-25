#ifndef _LAB1_8
#define _LAB1_8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_BASE 36
#define MAX_TOKEN_LEN 256
#define MAX_OUTPUT_LEN 128

typedef enum {
    SUCCESS = 0,
    INCORRECT_INPUT,
    INCORRECT_BASE
} BadType;

int char_to_value(char c);
char value_to_char(int value);
BadType validate_number(const char *s, int base);
long long convert_to_decimal(const char *s, int base);
void convert_from_decimal(long long n, int base, char *output_s);
void normalize_string(const char *input_s, char *output_s);

#endif