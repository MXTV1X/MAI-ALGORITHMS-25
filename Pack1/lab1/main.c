#include "lab1.h"

int main(int count, char *args[]) {
    if (count != 3) {
        printf("Некорректный ввод.\n", args[0]);
        return INCORRECT_INPUT;
    }

    if (args[2][0] != '-' && args[2][0] != '/') {
        printf("Флаг должен начинаться с '-' или '/'.\n");
        return INCORRECT_FLAG;
    }

    char* endptr;
    long result = strtol(args[1], &endptr, 10);
    if (*endptr != '\0') {
        printf("Некорректный ввод числа.\n");
        return INCORRECT_INPUT;
    }

    if (result > INT_MAX || result < INT_MIN) {
        printf("Произошло переполнение!\n");
        return OVERFLOW;
    }

    int x = (int)result;

    if (strcmp(args[2], "-h") == 0 || strcmp(args[2], "/h") == 0) {
        if (x <= 0) {
            printf("Для флага -h число должно быть натуральным.\n");
            return INCORRECT_INPUT;
        }
        Multiple(x);
    }
    else if (strcmp(args[2], "-p") == 0 || strcmp(args[2], "/p") == 0) {
        Divisibility(x);
    }
    else if (strcmp(args[2], "-s") == 0 || strcmp(args[2], "/s") == 0) {
        ConvertToHex(x);
    }
    else if (strcmp(args[2], "-e") == 0 || strcmp(args[2], "/e") == 0) {
        if (x < 1 || x > 10) {
            printf("Для флага -e число должно быть от 1 до 10 включительно.\n");
            return INCORRECT_INPUT;
        }
        Degree(x);
    }
    else if (strcmp(args[2], "-a") == 0 || strcmp(args[2], "/a") == 0) {
        if (x < 1) {
            printf("Для флага -a число должно быть натуральным.\n");
            return INCORRECT_INPUT;
        }
        printf("%lu\n", Sum(x));
    }
    else if (strcmp(args[2], "-f") == 0 || strcmp(args[2], "/f") == 0) {
        if (x < 0 || x > 20) {
            printf("Некорректный ввод.\n");
            return INCORRECT_INPUT;
        }
        printf("%lu\n", Factorial(x));
    }
    else {
        printf("Неверный флаг. Доступные флаги: -h, -p, -s, -e, -a, -f\n");
        return INCORRECT_FLAG;
    }
    
    return 0;
}