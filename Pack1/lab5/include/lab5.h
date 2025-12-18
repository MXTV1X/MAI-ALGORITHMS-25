#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_FILE 256

typedef enum{
    SUCCESS = 0,
    BAD_INP,
    OPEN_ERR,
    ALLOC_ERR
}Code;

int is_latin_letter(char c);
int is_arabic_digit(char c);
int is_space(char c);
void process_d_flag(FILE *input, FILE *output);
void process_i_flag(FILE *input, FILE *output);
void process_s_flag(FILE *input, FILE *output);
void process_a_flag(FILE *input, FILE *output);