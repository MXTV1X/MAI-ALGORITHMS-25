#include "lab7.h"
#include <string.h>
#include <ctype.h>
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

int find_min_base(const char *s) {
    int max_value = -1;
    int value;

    for (int i = 0; s[i] != '\0'; i++) {
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
    long long power_of_base = 1;
    int value;
    int len = strlen(s);

    for (int i = len - 1; i >= 0; i--) {
        value = char_to_value(s[i]);
        
        if (value == -1 || value >= base) {
            return -1; 
        }
        
        if (power_of_base > 0 && value > LLONG_MAX / power_of_base) {
             return -1; 
        }
        long long term = value * power_of_base;

        if (result > LLONG_MAX - term) {
             return -1; 
        }
        result += term;
        
        if (i > 0) {
             if (power_of_base > LLONG_MAX / base) {
                 return -1; 
             }
             power_of_base *= base;
        }
    }

    return result;
}

void normalize_number(const char *input_s, char *output_s) {
    if (!input_s || !output_s) {
        output_s[0] = '\0';
        return;
    }

    int i = 0;
    while (input_s[i] == '0') {
        i++;
    }

    if (input_s[i] == '\0') {
        if (i > 0) {
            output_s[0] = '0';
            output_s[1] = '\0';
        } else {
            output_s[0] = '\0';
        }
        return;
    }

    int j = 0;
    while (input_s[i] != '\0') {
        output_s[j] = toupper(input_s[i]);
        i++;
        j++;
    }
    output_s[j] = '\0';
}