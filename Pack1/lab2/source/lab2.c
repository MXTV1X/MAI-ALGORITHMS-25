#include "lab2.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

static int estimate_limit(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 3;
    if (n == 2) return 4;
    
    double log_n = log((double)n);
    double log_log_n = log(log_n);
    double estimate = n * (log_n + log_log_n);
    int limit = (int)(estimate * 1.2) + 1000; // Оценка верхней границы для поиска n-го простого
    if (limit < 20) limit = 20;
    
    return limit;
}

static bool* atkin_sieve(int limit) {
    bool* is_prime = (bool*)malloc((limit + 1) * sizeof(bool));
    if (!is_prime) return NULL;

    memset(is_prime, 0, (limit + 1) * sizeof(bool));

    if (limit >= 2) is_prime[2] = true;
    if (limit >= 3) is_prime[3] = true;
    if (limit < 5) return is_prime;

    int sqrt_limit = (int)sqrt((double)limit);
    
    int x2 = 0;
    for (int i = 1; i <= sqrt_limit; ++i) {
        x2 += 2 * i - 1;
        int y2 = 0;
        int n;
        for (int j = 1; j <= sqrt_limit; ++j) {
            y2 += 2 * j - 1;
            
            n = 4 * x2 + y2;
            if ((n <= limit) && (n % 12 == 1 || n % 12 == 5))
                is_prime[n] = !is_prime[n];
            
            // n = 3 * x2 + y2; 
            n -= x2;
            if ((n <= limit) && (n % 12 == 7))
                is_prime[n] = !is_prime[n];
            
            // n = 3 * x2 - y2;
            n -= 2 * y2;
            if ((i > j) && (n <= limit) && (n % 12 == 11))
                is_prime[n] = !is_prime[n];
        }
    }
    
    // Исключение кратных квадратам простых чисел
    for (int i = 5; i <= sqrt_limit; i++) {
        if (is_prime[i]) {
            int k = i * i;
            for (int j = k; j <= limit; j += k) {
                is_prime[j] = false;
            }
        }
    }
    
    return is_prime;
}

int find_nth_prime(int n) {
    if (n <= 0) return -1;
    if (n == 1) return 2;
    if (n == 2) return 3;
    
    // Верхняя граница поиска
    int limit = estimate_limit(n);
    
    bool* is_prime = atkin_sieve(limit);
    if (!is_prime) return -1;
    
    int count = 0;
    int result = -1;
    
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            count++;
            if (count == n) {
                result = i;
                break;
            }
        }
    }
    
    if (result == -1) {
        free(is_prime);
        limit = limit * 2;
        is_prime = atkin_sieve(limit);
        if (!is_prime) return -1;
        
        count = 0;
        for (int i = 2; i <= limit; i++) {
            if (is_prime[i]) {
                count++;
                if (count == n) {
                    result = i;
                    break;
                }
            }
        }
    }

    free(is_prime);

    return result;
}