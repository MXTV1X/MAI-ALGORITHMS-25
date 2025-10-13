#include "lab3.h"
#include <stdbool.h>
#include <math.h>

static void solve_one(double eps, double a, double b, double c) {
    if (fabs(a) < eps) {
        if (fabs(b) < eps) {
            if (fabs(c) < eps) {
                printf("Бесконечно много решений\n");
            } else {
                printf("Нет решений\n");
            }
        } else {
            double x = -c / b;
            printf("%.1f\n", x);
        }
        return;
    }

    double D = b * b - 4 * a * c;

    if (fabs(D) < eps) {
        double x = -b / (2 * a);
        printf("%.1f\n", x);
    } else if (D < 0) {
        printf("Нет вещественных корней\n");
    } else {
        double sqrtD = sqrt(D);
        double x1 = (-b - sqrtD) / (2 * a);
        double x2 = (-b + sqrtD) / (2 * a);
        printf("%.1f, %.1f\n", x1, x2);
    }
}

void Solve_Equation(double eps, double a, double b, double c) {
    double perms[6][3] = {
        {a, b, c}, {a, c, b}, {b, a, c},
        {b, c, a}, {c, a, b}, {c, b, a}
    };
    
    int unique_count = 0;
    
    for (int i = 0; i < 6; i++) {
        bool is_unique = true;
        for (int j = 0; j < i; j++) {
            if (fabs(perms[j][0] - perms[i][0]) < eps &&
                fabs(perms[j][1] - perms[i][1]) < eps &&
                fabs(perms[j][2] - perms[i][2]) < eps) {
                is_unique = false;
                break;
            }
        }
        
        if (!is_unique) continue;
        
        unique_count++;
        printf("%.1f %.1f %.1f: ", perms[i][0], perms[i][1], perms[i][2]);
        solve_one(eps, perms[i][0], perms[i][1], perms[i][2]);
    }
}

bool Multiplicity(int num, int del) {
    if (num == 0 || del == 0) return false;
    return (num % del == 0);
}

bool Triangle(double eps, double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) return false;
    if (a + b <= c || a + c <= b || b + c <= a) return false;
    
    if (fabs(a*a + b*b - c*c) <= eps) return true;
    if (fabs(a*a + c*c - b*b) <= eps) return true;
    if (fabs(b*b + c*c - a*a) <= eps) return true;
    
    return false;
}