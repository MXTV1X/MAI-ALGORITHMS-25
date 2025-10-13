#include "lab3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argv[1][0] != '-' && argv[1][0] != '/') {
        printf("Флаг должен начинаться с '-' или '/'.\n");
        return INCORRECT_FLAG;
    }

    if (strcmp(argv[1], "-q") == 0 || strcmp(argv[1], "/q") == 0) {
        if (argc != 6) {
            printf("Для флага -q требуется 4 значения: eps a b c\n");
            return INCORRECT_INPUT;
        }

        char *end;
        double eps = strtod(argv[2], &end);
        if (*end != '\0') return INCORRECT_INPUT;
        
        double a = strtod(argv[3], &end);
        if (*end != '\0') return INCORRECT_INPUT;
        
        double b = strtod(argv[4], &end);
        if (*end != '\0') return INCORRECT_INPUT;
        
        double c = strtod(argv[5], &end);
        if (*end != '\0') return INCORRECT_INPUT;
        
        if (!isfinite(eps) || !isfinite(a) || !isfinite(b) || !isfinite(c)) {
            printf("Некорректные числа (inf/nan).\n");
            return INCORRECT_INPUT;
        }

        if (eps <= 0) {
            printf("Эпсилон должен быть положительным.\n");
            return INCORRECT_INPUT;
        }

        Solve_Equation(eps, a, b, c);

        return 0;
    }

    else if (strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "/m") == 0) {
        if (argc != 4) {
            printf("Для флага -m требуется 2 значения: num и del.\n");
            return INCORRECT_INPUT;
        }

        char *end1, *end2;
        long num_long = strtol(argv[2], &end1, 10);
        long del_long = strtol(argv[3], &end2, 10);

        if (*end1 != '\0' || *end2 != '\0') {
            printf("Некорректный ввод числа.\n");
            return INCORRECT_INPUT;
        }

        if (num_long > INT_MAX || num_long < INT_MIN ||
            del_long > INT_MAX || del_long < INT_MIN) {
            printf("Произошло переполнение!\n");
            return OVERFLOW;
        }

        int num = (int)num_long;
        int del = (int)del_long;

        if (Multiplicity(num, del)) printf("%d кратно %d\n", num, del);
        else printf("%d не кратно %d\n", num, del);

        return 0;
    }

    else if (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "/t") == 0) {
        if (argc != 6) {
            printf("Для флага -t требуется 4 значения: eps a b c\n");
            return INCORRECT_INPUT;
        }

        char *end;
        double eps = strtod(argv[2], &end);
        if (*end != '\0') return INCORRECT_INPUT;
        
        double a = strtod(argv[3], &end);
        if (*end != '\0') return INCORRECT_INPUT;
        
        double b = strtod(argv[4], &end);
        if (*end != '\0') return INCORRECT_INPUT;
        
        double c = strtod(argv[5], &end);
        if (*end != '\0') return INCORRECT_INPUT;
        
        if (!isfinite(eps) || !isfinite(a) || !isfinite(b) || !isfinite(c)) {
            printf("Некорректные числа (inf/nan).\n");
            return INCORRECT_INPUT;
        }
        
        if (eps <= 0) {
            printf("Эпсилон должен быть положительным.\n");
            return INCORRECT_INPUT;
        }

        if (Triangle(eps, a, b, c)) printf("Прямоугольный треугольник.\n");
        else printf("Не прямоугольный треугольник.\n");

        return 0;
    }

    else {
        printf("Неверный флаг. Доступные флаги: -q, -m, -t\n");
        return INCORRECT_FLAG;
    }

    return 0;
}