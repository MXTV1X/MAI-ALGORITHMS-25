#include "lab1.h"
#include <stdio.h>

void Multiple(int x){
    int count = 0;
    for (int i = 1; i <= 100; i++){
        if(i % x == 0){
            printf("%d ", i);
            count++;
        }
    }
    if (count == 0){
        printf("Таких чисел нет.\n");
    }
    printf("\n");
}

void Divisibility(int x){
    if (x <= 0 || x == 1){
        printf("Не является ни простым, ни составным.\n");
    }
    else if(x > 0 && x != 1){
        bool boolean = true;
        for (int i = 2; i * i <= x; i++){
            if (x % i == 0){
                printf("Число - составное.\n");
                boolean = false;
                break;
            }
        }
        if (boolean){
            printf("Число - простое.\n");
        }
    }
}

void ConvertToHex(int x){
    if (x == 0) {
        printf("0\n");
        return;
    }
    
    int del = 1;
    int num = x;
    while (num / del >= 16) {
        del *= 16;
    }

    while (del > 0) {
        int t = num / del;
        if(0 <= t && t <= 9){
            printf("%d", t);
        }
        else if(10 <= t && t <= 15){
            char l = 'A' - 10 + t;
            printf("%c", l);
        }
        num %= del;
        del /= 16;
        if (del > 0) {
            printf(" ");
        }
    }
    printf("\n");
}


uint64_t power(int x, int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    uint64_t res = 1;
    uint64_t base = x;
    for (int i = 0; i < n; i++) {
        res *= base;
    }
    return res;
}

void Degree(int x){
    printf("%7c",'|');
    for(int i = 1; i <= x; i++){
        printf("%11d| ", i);
    }
    printf("\n");
    
    if (1 <= x && x <= 10){
        for (int i = 1; i <= 10; i++){
            printf("%6d|", i);
            
            for (int j = 1; j <= x; j++){
                printf("%11lu| ", power(i, j));
            }
            printf("\n");
        }
    }
}


uint64_t Sum(int x){
    uint64_t sum = (x * (x + 1)) / 2;
    return sum;
}


uint64_t Factorial(int x){
    uint64_t fac = 1;
    for (int i = 2; i <= x; i++){
        fac *= i;
    }
    return fac;
}
