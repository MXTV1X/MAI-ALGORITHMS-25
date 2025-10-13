#ifndef _LAB1_6
#define _LAB1_6

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    SUCCESS,
    INCORRECT_INPUT,
    INCORRECT_EPS
} BadType;

double func_a(double x);  // ln(1+x)/x
double func_b(double x);  // e^(-x^2/2)
double func_c(double x);  // ln(1/(1-x))
double func_d(double x);  // x^x

double trapezoidal_integral(double (*func)(double), double a, double b, double epsilon);

#endif