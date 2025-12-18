#include "lab5.h"

int is_latin_letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int is_arabic_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_space(char c) {
    return c == ' ';
}

void process_d_flag(FILE *input, FILE *output) {
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        if (!is_arabic_digit(ch)) {
            fputc(ch, output);
        }
    }
}

void process_i_flag(FILE *input, FILE *output) {
    int ch;
    size_t buffer_size = 128;
    size_t length = 0;
    char* buffer = (char*)malloc(buffer_size);
    
    if (buffer == NULL) {
        return ALLOC_ERR; 
    }
    
    while ((ch = fgetc(input)) != EOF) {
        if (length >= buffer_size - 1) {
            buffer_size *= 2;
            char* new_buffer = (char*)realloc(buffer, buffer_size);
            if (new_buffer == NULL) {
                free(buffer);
                return ALLOC_ERR; 
            }
            buffer = new_buffer;
        }
        
        if (ch == '\n') {
            buffer[length] = '\0';
            int count = 0;
            for (size_t i = 0; i < length; i++) {
                if (is_latin_letter(buffer[i])) {
                    count++;
                }
            }
            fprintf(output, "%d\n", count);
            length = 0;
        } else {
            buffer[length++] = (char)ch;
        }
    }

    if (length > 0) {
        buffer[length] = '\0';
        int count = 0;
        for (size_t i = 0; i < length; i++) {
            if (is_latin_letter(buffer[i])) {
                count++;
            }
        }
        fprintf(output, "%d\n", count);
    }
    
    free(buffer);
}

void process_s_flag(FILE *input, FILE *output) {
    int ch;
    size_t buffer_size = 128;
    size_t length = 0;
    char* buffer = (char*)malloc(buffer_size);
    
    if (buffer == NULL) {
        return ALLOC_ERR;
    }
    
    while ((ch = fgetc(input)) != EOF) {
        if (length >= buffer_size - 1) {
            buffer_size *= 2;
            char* new_buffer = (char*)realloc(buffer, buffer_size);
            if (new_buffer == NULL) {
                free(buffer);
                return ALLOC_ERR;
            }
            buffer = new_buffer;
        }
        
        if (ch == '\n') {
            buffer[length] = '\0';
            int count = 0;
            for (size_t i = 0; i < length; i++) {
                if (!is_latin_letter(buffer[i]) && 
                    !is_arabic_digit(buffer[i]) && 
                    !is_space(buffer[i])) {
                    count++;
                }
            }
            fprintf(output, "%d\n", count);
            length = 0;
        } else {
            buffer[length++] = (char)ch;
        }
    }
    
    if (length > 0) {
        buffer[length] = '\0';
        int count = 0;
        for (size_t i = 0; i < length; i++) {
            if (!is_latin_letter(buffer[i]) && 
                !is_arabic_digit(buffer[i]) && 
                !is_space(buffer[i])) {
                count++;
            }
        }
        fprintf(output, "%d\n", count);
    }
    
    free(buffer);
}

void process_a_flag(FILE *input, FILE *output) {
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        if (is_arabic_digit(ch)) {
            fputc(ch, output);
        } else {
            fprintf(output, "%02X", (unsigned char)ch);
        }
    }
}
