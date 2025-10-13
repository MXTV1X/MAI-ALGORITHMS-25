#include "lab2.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    if (scanf("%d", &T) != 1 || T <= 0) {
        printf("Ошибка: некорректное количество запросов\n");
        return INCORRECT_INPUT;
    }
    
    int* queries = (int*)malloc(T * sizeof(int));
    if (!queries) {
        printf("Ошибка выделения памяти\n");
        return MEMORY_ALLOCATION_ERROR;
    }
    
    for (int i = 0; i < T; i++) {
        if (scanf("%d", &queries[i]) != 1 || queries[i] <= 0) {
            printf("Ошибка: некорректный запрос %d\n", i + 1);
            free(queries);
            return INCORRECT_REQUEST;
        }
    }
    
    for (int i = 0; i < T; i++) {
        int prime = find_nth_prime(queries[i]);
        
        if (prime == -1) {
            printf("Ошибка при поиске %d-го простого числа\n", queries[i]);
        } else {
            printf("%d\n", prime);
        }
    }

    free(queries);
    
    return 0;
}