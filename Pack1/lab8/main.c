#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "lab8.h"

int main(int argc, char *argv[]) {
    int base;
    char token[MAX_TOKEN_LEN];
    long long max_abs_value = 0;
    long long max_abs_number = 0;
    int bases_to_convert[] = {9, 18, 27, 36};
    
    printf("Введите основание системы счисления (2-36): ");
    if (scanf("%d", &base) != 1) {
        fprintf(stderr, "Ошибка: Не удалось прочитать основание.\n");
        return INCORRECT_INPUT;
    }
    
    if (base < 2 || base > MAX_BASE) {
        fprintf(stderr, "Ошибка: Основание должно быть в диапазоне [2, 36].\n");
        return INCORRECT_BASE;
    }

    printf("Введите целые числа (или 'Stop' для завершения):\n");
    while (scanf("%s", token) == 1) {
        if (strcmp(token, "Stop") == 0) {
            break;
        }

        if (validate_number(token, base) != SUCCESS) {
            fprintf(stderr, "Предупреждение: Пропущено некорректное число '%s' для основания %d.\n", token, base);
            continue;
        }
        
        long long current_decimal = convert_to_decimal(token, base);

        if (current_decimal == LLONG_MIN) {
             fprintf(stderr, "Предупреждение: Пропущено число '%s' из-за потенциального переполнения long long.\n", token);
             continue;
        }

        long long current_abs = (current_decimal < 0) ? -current_decimal : current_decimal;

        if (current_abs > max_abs_value) {
            max_abs_value = current_abs;
            max_abs_number = current_decimal;
        }
    }

    if (max_abs_value == 0 && max_abs_number == 0) {
        printf("Числа не были введены или все введенные числа равны нулю.\n");
        return SUCCESS;
    }

    char normalized_str[MAX_OUTPUT_LEN];
    char temp_str[MAX_OUTPUT_LEN];
    
    convert_from_decimal(max_abs_number, base, temp_str); 
    normalize_string(temp_str, normalized_str);

    printf("Максимальное по модулю число (в осн. %d, без ведущих нулей): %s\n", base, normalized_str);
    printf("Десятичное значение: %lld\n", max_abs_number);

    char output_base_str[MAX_OUTPUT_LEN];
    for (size_t i = 0; i < sizeof(bases_to_convert) / sizeof(bases_to_convert[0]); i++) {
        int target_base = bases_to_convert[i];

        if (target_base < 2 || target_base > MAX_BASE) {
            printf("Ошибка: Целевая база %d некорректна.\n", target_base);
            continue;
        }
        
        convert_from_decimal(max_abs_number, target_base, output_base_str);
        printf("В основании %2d: %s\n", target_base, output_base_str);
    }
    
    return SUCCESS;
}