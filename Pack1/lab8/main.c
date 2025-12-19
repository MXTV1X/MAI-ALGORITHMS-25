#include "lab8.h"

int main() {
    int base;
    printf("Введите основание системы счисления (2-36): ");
    if (scanf("%d", &base) != 1 || base < 2 || base > 36) {
        printf("Ошибка: некорректное основание.\n");
        return 1;
    }

    char token[MAX_TOKEN_LEN];
    long long max_abs = -1;
    long long winner = 0;
    int found = 0;

    printf("Введите числа (для окончания введите 'Stop'):\n");
    while (scanf("%255s", token) == 1) {
        if (strcmp(token, "Stop") == 0) break;

        if (validate_number(token, base) == SUCCESS) {
            long long val = convert_to_decimal(token, base);
            long long current_abs = (val < 0) ? -val : val;
            
            if (!found || current_abs > max_abs) {
                max_abs = current_abs;
                winner = val;
                found = 1;
            }
        }
    }

    if (found) {
        int targets[] = {9, 18, 27, 36};
        char buf[MAX_OUTPUT_LEN], norm[MAX_OUTPUT_LEN];
        
        printf("\nРезультаты для максимального по модулю числа:\n");
        for (int i = 0; i < 4; i++) {
            convert_from_decimal(winner, targets[i], buf);
            normalize_string(buf, norm);
            printf("Основание %d: %s\n", targets[i], norm);
        }
    } else {
        printf("Числа не были введены.\n");
    }

    return 0;
}