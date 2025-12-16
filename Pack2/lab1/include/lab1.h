#ifndef _LAB2_1
#define _LAB2_1

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

typedef enum {
    NO_REPR = 0,
    HAS_REPR = 1,
    INCORRECT = -1
} final_repr_res;

int gcd(int a, int b);
void final_representation(int number_system, int n, final_repr_res out[], ...);


#endif