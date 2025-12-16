#include "../include/lab1.h"

int gcd(int a, int b){
    int _a = a > b ? a : b;
    int _b = a + b - _a;
    int rem;
    while((rem = _a % _b) != 0){
        //_a %= _b;
        // _a = rem;
        int temp = rem;
        _a = _b;
        _b = temp;
    }
    return _b;
}

void final_representation(int number_system, int n, final_repr_res out[], ...){
    double elem;
    va_list factor;
    va_start(factor, out);
    for(int i = 0; i < n; i++){
        elem = va_arg(factor, double);
        if (elem < 0 || elem > 1){
            out[i] = INCORRECT;
            continue;
        }
        int denominator = 1;
        int numerator;
        for(int j = 0; j < 15; j++){
            elem *= 10;
            denominator *= 10;
            if (fabs(elem - trunc(elem)) < 1e-15){
                numerator = (int)elem;
                break;
            }
        }

        int _gcd = gcd(numerator, denominator);
        denominator /= _gcd, numerator /= _gcd;

        bool finite = true;
        int temp_denom = denominator;
        for (int j = 2; j * j <= temp_denom; j++){
            if (temp_denom % j == 0) {
                if (number_system % j != 0) {
                    finite = false;
                    break;
                }
                while (temp_denom % j == 0) {
                    temp_denom /= j;
                }
            }
        }
        if (temp_denom > 1 && number_system % temp_denom != 0) {
            finite = false;
        }
        if (finite) {
            out[i] = HAS_REPR;
        } else {
            out[i] = NO_REPR;
        }
    }
    va_end(factor);
}