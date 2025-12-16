#ifndef _LAB1_5
#define _LAB1_5

#define MAX_LEN 50
#define BUFFER_SIZE 1024

#define IS_FLAG(a, b) strcmp(a, b) == 0

char* remove_arabic_digits(const char* buff, char* res);

char* count_latin_letters(const char* buff, char* res);

char* count_rare_symbols(const char* buff, char* res);

char* replace_except_digits(const char* buff, char* res);

#endif