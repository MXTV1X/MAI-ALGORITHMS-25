#include "lab6.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#define EPS_SMALL 1e-6

double func_a(double x) {
    if (fabs(x) < EPS_SMALL) {
        return 1.0;
    }
    return log(1.0 + x) / x;
}

double func_b(double x) {
    return exp(-x * x / 2.0);
}

double func_c(double x) {
    if (fabs(1.0 - x) < EPS_SMALL) {
        return -log(EPS_SMALL);
    }
    return -log(1.0 - x);
}

double func_d(double x) {
    if (fabs(x) < EPS_SMALL) {
        return 1.0;
    }
    return exp(x * log(x));
}

// Метод трапеций с автоматическим выбором числа разбиений
double trapezoidal_integral(double (*func)(double), double a, double b, double epsilon) {
    int n = 1;
    double h = b - a;
    double sum = (func(a) + func(b)) / 2.0;
    double prev_integral = 0.0;
    double integral = sum * h;
    
    for (int iter = 0; iter < 20; iter++) {
        if (fabs(integral - prev_integral) < epsilon) {
            break;
        }
        
        prev_integral = integral;
        double midpoint_sum = 0.0;
        
        // Добавляем средние точки для новых отрезков
        for (int i = 0; i < n; i++) {
            double x = a + (i + 0.5) * h;
            midpoint_sum += func(x);
        }
        
        // Новое приближение: старое + средние точки * h
        integral = (integral + h * midpoint_sum) / 2.0;
        
        n *= 2;
        h /= 2.0;
    }
    
    return integral;
}