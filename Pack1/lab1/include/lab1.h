#ifndef _LAB1_1
#define _LAB1_1

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    INCORRECT_INPUT,
    OVERFLOW,
    NEGATIVE_NUMBER,
    INCORRECT_FLAG
} BadType;

void Multiple(int x);
void Divisibility(int x);
void ConvertToHex(int x);
uint64_t power(int x, int n);
void Degree(int x);
uint64_t Sum(int x);
uint64_t Factorial(int x);

#endif