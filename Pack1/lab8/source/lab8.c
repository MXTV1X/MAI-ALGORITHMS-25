#include "lab8.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

int char_to_value(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else if (isalpha(c)) {
        char upper_c = toupper(c); 
        return 10 + (upper_c - 'A');
    }
    return -1;
}

char value_to_char(int value) {
    if (value >= 0 && value <= 9) {
        return (char)('0' + value);
    } else if (value >= 10 && value <= 35) {
        return (char)('A' + (value - 10));
    }
    return '?';ы
}

BadType validate_number(const char *s, int base) {
    if (base < 2 || base > MAX_BASE) return INCORRECT_BASE;

    int i = 0;
    if (s[0] == '-' || s[0] == '+') {
        i = 1;
    }
    
    if (s[i] == '\0') return INCORRECT_INPUT;

    for (; s[i] != '\0'; i++) {
        int value = char_to_value(s[i]);
        if (value == -1 || value >= base) {
            return INCORRECT_INPUT;
        }
    }
    return SUCCESS;
}

long long convert_to_decimal(const char *s, int base) {
    long long result = 0;
    long long power_of_base = 1;
    int value;
    int len = strlen(s);
    int start_index = 0;
    int is_negative = 0;

    if (s[0] == '-') {
        is_negative = 1;
        start_index = 1;
    } else if (s[0] == '+') {
        start_index = 1;
    }
    
    for (int i = len - 1; i >= start_index; i--) {
        value = char_to_value(s[i]);
        
        if (value < 0 || value >= base) {
            return LLONG_MIN; 
        }

        if (value != 0 && power_of_base > LLONG_MAX / value) {
             return LLONG_MIN; 
        }
        long long term = power_of_base * value;

            return LLONG_MIN; 
        }
        result += term;
        
        if (i > start_index) {
             if (power_of_base > LLONG_MAX / base) {
                 return LLONG_MIN; 
             }
             power_of_base *= base;
        }
    }

    if (is_negative) {
        if (result == LLONG_MIN) {
            return LLONG_MIN; 
        }
        return -result;
    }
    return result;
}

void convert_from_decimal(long long n, int base, char *output_s) {
    if (n == 0) {
        output_s[0] = '0';
        output_s[1] = '\0';
        return;
    }

    int is_negative = (n < 0);
    long long abs_n = is_negative ? -n : n;
    
    char temp[MAX_OUTPUT_LEN]; 
    int i = 0;

    while (abs_n > 0) {
        int remainder = abs_n % base;
        temp[i++] = value_to_char(remainder);
        abs_n /= base;
    }
    
    if (is_negative) {
        temp[i++] = '-';
    }
    temp[i] = '\0';

    int len = i;
    for (int j = 0; j < len; j++) {
        output_s[j] = temp[len - 1 - j];
    }
    output_s[len] = '\0';
}


void normalize_string(const char *input_s, char *output_s) {
    if (!input_s || !output_s) {
        output_s[0] = '\0';
        return;
    }
    
    int i = 0;
    int is_negative = 0;

    if (input_s[0] == '-') {
        is_negative = 1;
        i = 1;
    } else if (input_s[0] == '+') {
        i = 1;
    }

    while (input_s[i] == '0' && input_s[i+1] != '\0') {
        i++;
    }

    if (input_s[i] == '\0' || (input_s[i] == '0' && input_s[i+1] == '\0')) {
        output_s[0] = '0';
        output_s[1] = '\0';
        return;
    }

    int j = 0;
    if (is_negative) {
        output_s[j++] = '-';
    }

    while (input_s[i] != '\0') {
        output_s[j] = input_s[i];
        i++;
        j++;
    }
    output_s[j] = '\0';
}