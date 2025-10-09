#include "lab1/include/lab1.h"
#include <stdio.h>

int main(int count, char *args[]){
    if (count != 3){
        printf("Некорректный ввод.\n");
        return INCORRECT_INPUT;
    }

    char* endptr;
    long result = strtol(args[1], &endptr, 10);
    if(*endptr != 0){
        printf("Некорректный ввод.\n");
        return INCORRECT_INPUT;
    };
    
    if(result > INT_MAX || result  < INT_MIN){
        printf("Произошло переполнение! Значение слишком большое.\n");
        return OVERFLOW;
    }
    
    int x = (int) result;

    if(x < 0){
        printf("Было введено отрицательное число.\n");
        return NEGATIVE_NUMBER;
    }

    if(strcmp(args[2], "-h") == 0 || strcmp(args[2], "/h") == 0){
        if (1 <= x && x <= 100){
            Multiple(x);
        }
        else{
            printf("Некорректный ввод.\n");
            return INCORRECT_INPUT;
        }
    }
    else if(strcmp(args[2], "-p") == 0 || strcmp(args[2], "/p") == 0){
        Divisibility(x);
    }
    else if(strcmp(args[2], "-s") == 0 || strcmp(args[2], "/s") == 0){
        ConvertToHex(x);
    }
    else if(strcmp(args[2], "-e") == 0 || strcmp(args[2], "/e") == 0){
        if (1 <= x && x <= 10){
        Degree(x);
        }
        else{
            printf("Некорректный ввод.\n");
            return INCORRECT_INPUT;
        }

    }
    else if(strcmp(args[2], "-a") == 0 || strcmp(args[2], "/a") == 0){
        Sum(x);
        printf("%lu\n",Sum(x));
    }
    else if(strcmp(args[2], "-f") == 0 || strcmp(args[2], "/f") == 0){
        printf("%lu\n",Factorial(x));
    }
    else{
        printf("Неверный флаг.\n");
        return INCORRECT_FLAG;
    }
    return 0;
}