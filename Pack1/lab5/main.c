#include "lab5.h"



int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Использование: %s <флаг> <входной_файл> [выходной_файл]\n", argv[0]);
        return BAD_INP;
    }

    char *flag = argv[1];
    char *input_filename = argv[2];
    char output_filename[NAME_FILE];
    char *provided_output = NULL;
    
    if ((flag[0] != '-' && flag[0] != '/') || strlen(flag) < 2 || strlen(flag) > 3) {
        printf("Некорректный флаг: %s\n", flag);
        return BAD_INP;
    }
    if (flag[1] == 'n' && argc >= 4) {
        provided_output = argv[3];
    }

    if (provided_output != NULL) {
        strncpy(output_filename, provided_output, NAME_FILE);
    } else {
        const char *prefix = "out_";
        size_t total_len = strlen(prefix) + strlen(input_filename);
        if (total_len >= NAME_FILE) {
            printf("Ошибка: сгенерированное имя файла слишком длинное\n");
            return BAD_INP;
        }
        
        strcpy(output_filename, prefix);
        strcat(output_filename, input_filename);
    }
    
    FILE *input = fopen(input_filename, "r");
    if (!input) {
        printf("Не удалось открыть входной файл: %s\n", input_filename);
        return OPEN_ERR;
    }
    
    FILE *output = fopen(output_filename, "w");
    if (!output) {
        printf("Не удалось создать выходной файл: %s\n", output_filename);
        fclose(input);
        return OPEN_ERR;
    }
    
    char operation = flag[1];
    
    if (flag[1] == 'n') {
        if (strlen(flag) != 3) {
            printf("Некорректный флаг: %s\n", flag);
            return BAD_INP;
        }
        operation = flag[2];  
        if (strchr("disa", operation) == NULL) {
            printf("Неизвестная операция: %c\n", operation);
            return BAD_INP;
        }
    } else {
        if (strlen(flag) != 2) {
            printf("Некорректный флаг: %s\n", flag);
            return BAD_INP;
        }
        operation = flag[1]; 
    }
    
    switch (operation) {
        case 'd':
            process_d_flag(input, output);
            break;
        case 'i':
            process_i_flag(input, output);
            break;
        case 's':
            process_s_flag(input, output);
            break;
        case 'a':
            process_a_flag(input, output);
            break;
        default:
            printf("Неизвестный флаг: %c\n", operation);
            fclose(input);
            fclose(output);
            return BAD_INP;
    }
    
    
    fclose(input);
    fclose(output);
    
    printf("Обработка завершена. Результат в файле: %s\n", output_filename);
    return SUCCESS;
}