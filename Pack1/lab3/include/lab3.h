#ifndef _LAB1_3
#define _LAB1_3

#include <stdbool.h>

typedef enum {
    SUCCESS,
    INCORRECT_INPUT,
    OVERFLOW,
    NEGATIVE_NUMBER,
    INCORRECT_FLAG
} BadType;

void Solve_Equation(double eps, double a, double b, double c);
bool Multiplicity(int num, int del);
bool Triangle(double eps, double a, double b, double c);
#endif