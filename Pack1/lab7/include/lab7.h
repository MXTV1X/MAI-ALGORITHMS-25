#ifndef _LAB1_7
#define _LAB1_7

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_BASE 36
#define MAX_TOKEN_LEN 256

typedef enum {
    SUCCESS = 0,
    INCORRECT_INPUT,
    INCORRECT_BASE
} BadType;

int char_to_value(char c);
int find_min_base(const char *s);
long long convert_to_decimal(const char *s, int base);
void normalize_number(const char *input_s, char *output_s);

#endif