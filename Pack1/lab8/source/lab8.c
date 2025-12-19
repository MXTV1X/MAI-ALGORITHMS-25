#include "lab8.h"

int char_to_value(char c) {
    if (isdigit(c)) return c - '0';
    if (isalpha(c)) return 10 + (toupper(c) - 'A');
    return -1;
}

char value_to_char(int value) {
    if (value >= 0 && value <= 9) return (char)('0' + value);
    if (value >= 10 && value <= 35) return (char)('A' + (value - 10));
    return '?';
}

BadType validate_number(const char *s, int base) {
    if (base < 2 || base > MAX_BASE) return INCORRECT_BASE;
    int i = (s[0] == '-' || s[0] == '+') ? 1 : 0;
    if (s[i] == '\0') return INCORRECT_INPUT;
    for (; s[i] != '\0'; i++) {
        int val = char_to_value(s[i]);
        if (val == -1 || val >= base) return INCORRECT_INPUT;
    }
    return SUCCESS;
}

long long convert_to_decimal(const char *s, int base) {
    long long result = 0;
    int is_negative = (s[0] == '-');
    int i = (s[0] == '-' || s[0] == '+') ? 1 : 0;

    for (; s[i] != '\0'; i++) {
        int val = char_to_value(s[i]);
        // Базовая проверка на переполнение
        if (result > (LLONG_MAX - val) / base) return LLONG_MAX; 
        result = result * base + val;
    }
    return is_negative ? -result : result;
}

void convert_from_decimal(long long n, int base, char *output_s) {
    if (n == 0) {
        strcpy(output_s, "0");
        return;
    }
    char temp[MAX_OUTPUT_LEN];
    int i = 0;
    int is_neg = (n < 0);
        
    unsigned long long abs_n;
    if (n == LLONG_MIN) {
        abs_n = (unsigned long long)LLONG_MAX + 1ULL;
    } else if (n < 0) {
        abs_n = (unsigned long long)(-n);
    } else {
        abs_n = (unsigned long long)n;
    }

    while (abs_n > 0) {
        temp[i++] = value_to_char(abs_n % base);
        abs_n /= base;
    }
    if (is_neg) temp[i++] = '-';
    
    for (int j = 0; j < i; j++) {
        output_s[j] = temp[i - 1 - j];
    }
    output_s[i] = '\0';
}

void normalize_string(const char *input_s, char *output_s) {
    int i = 0, j = 0;
    if (input_s[0] == '-' || input_s[0] == '+') {
        if (input_s[0] == '-') output_s[j++] = '-';
        i++;
    }
    while (input_s[i] == '0' && input_s[i+1] != '\0') i++;
    while (input_s[i] != '\0') output_s[j++] = input_s[i++];
    output_s[j] = '\0';
}