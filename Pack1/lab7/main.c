#include <stdio.h>
#include "lab7.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Использование: %s <входной_файл> <выходной_файл>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL) {
        perror("Ошибка открытия входного файла");
        return EXIT_FAILURE;
    }

    FILE *fout = fopen(argv[2], "w");
    if (fout == NULL) {
        perror("Ошибка открытия выходного файла");
        fclose(fin);
        return EXIT_FAILURE;
    }

    char token[MAX_TOKEN_LEN];
    char normalized_token[MAX_TOKEN_LEN];
    int min_base;
    long long decimal_value;

    while (fscanf(fin, "%255s", token) == 1) {
        normalize_number(token, normalized_token);

        if (normalized_token[0] == '\0') {
            continue;
        }

        if (normalized_token[0] == '0' && normalized_token[1] == '\0') {
            fprintf(fout, "0 2 0\n");
            continue;
        }

        min_base = find_min_base(normalized_token);

        if (min_base == -1) {
            fprintf(stderr, "Предупреждение: Пропущено некорректное число: %s\n", token);
            continue; 
        }
        
        decimal_value = convert_to_decimal(normalized_token, min_base);

        if (decimal_value == -1) {
            fprintf(stderr, "Предупреждение: Пропущено число из-за потенциального переполнения: %s\n", token);
            continue;
        }

        fprintf(fout, "%s %d %lld\n", normalized_token, min_base, decimal_value);
    }

    if (ferror(fin)) {
        perror("Ошибка чтения из входного файла");
    }
    
    fclose(fin);
    fclose(fout);

    printf("Обработка завершена. Результаты записаны в файл: %s\n", argv[2]);
    return EXIT_SUCCESS;
}