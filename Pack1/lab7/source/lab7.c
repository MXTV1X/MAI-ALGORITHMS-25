#include "lab7.h"

int char_to_value(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else if (isalpha(c)) {
        char upper_c = toupper(c);
        return 10 + (upper_c - 'A');
    }
    return -1;
}

int find_min_base(const char *s) {
    int max_value = -1;
    int value;
    int start_idx = 0;

    if (s[0] == '-' || s[0] == '+') {
        start_idx = 1;
    }

    if (s[start_idx] == '\0') {
        return -1;
    }

    for (int i = start_idx; s[i] != '\0'; i++) {
        value = char_to_value(s[i]);
        if (value == -1) {
            return -1;
        }
        if (value > max_value) {
            max_value = value;
        }
    }

    int min_base = max_value + 1;

    if (min_base < 2) {
        return 2;
    }
    if (min_base > MAX_BASE) {
        return -1;
    }
    
    return min_base;
}

long long convert_to_decimal(const char *s, int base) {
    long long result = 0;
    int is_negative = 0;
    int start_idx = 0;

    if (s[0] == '-') {
        is_negative = 1;
        start_idx = 1;
    } else if (s[0] == '+') {
        start_idx = 1;
    }

    if (s[start_idx] == '\0') {
        return -1;
    }

    for (int i = start_idx; s[i] != '\0'; i++) {
        int value = char_to_value(s[i]);
        
        if (value == -1 || value >= base) {
            return -1;
        }
        
        if (result > (LLONG_MAX - value) / base) {
            return -1;
        }
        
        result = result * base + value;
    }

    if (is_negative) {
        result = -result;
    }

    return result;
}

void normalize_number(const char *input_s, char *output_s) {
    if (!input_s || !output_s) {
        output_s[0] = '\0';
        return;
    }

    int i = 0;
    int sign_present = 0;
    int is_negative = 0;

    if (input_s[0] == '-') {
        is_negative = 1;
        sign_present = 1;
        i = 1;
    } else if (input_s[0] == '+') {
        sign_present = 1;
        i = 1;
    }

    while (input_s[i] == '0') {
        i++;
    }

    if (input_s[i] == '\0') {
        if (i > sign_present) {
            output_s[0] = '0';
            output_s[1] = '\0';
        } else if (sign_present) {
            output_s[0] = '0';
            output_s[1] = '\0';
        } else {
            output_s[0] = '\0';
        }
        return;
    }

    int j = 0;
    if (is_negative) {
        output_s[j++] = '-';
    }

    while (input_s[i] != '\0') {
        output_s[j] = toupper(input_s[i]);
        i++;
        j++;
    }
    output_s[j] = '\0';
}