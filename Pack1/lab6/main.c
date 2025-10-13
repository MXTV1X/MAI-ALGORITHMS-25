#include "lab6.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Некорректный ввод.\n");
        return INCORRECT_INPUT;
    }
    
    char *endptr;
    double epsilon = strtod(argv[1], &endptr);
    
    if (*endptr != '\0' || epsilon <= 0.0) {
        printf("Ошибка: epsilon должно быть положительным вещественным числом\n");
        return INCORRECT_EPS;
    }

    double result_a = trapezoidal_integral(func_a, 0.0, 1.0, epsilon);
    printf("a) %.10f\n", result_a);
    
    double result_b = trapezoidal_integral(func_b, 0.0, 1.0, epsilon);
    printf("b) %.10f\n", result_b);
    
    double result_c = trapezoidal_integral(func_c, 0.0, 0.999999999, epsilon);
    printf("c) %.10f\n", result_c);
    
    double result_d = trapezoidal_integral(func_d, 0.0, 1.0, epsilon);
    printf("d) %.10f\n", result_d);

    return 0;
}