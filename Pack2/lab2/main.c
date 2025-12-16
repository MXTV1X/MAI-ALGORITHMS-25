#include "lab2.h"

#include <stdio.h>
#include <string.h>

int main() {
    char flag;
    char str1[256], str2[256];
    int n, err;
    char c;

    printf("Choose function (a-o): ");
    scanf(" %c", &flag);
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); // очистка буфера после scanf

    switch (flag) {
        case 'a': { // memchr
            printf("Enter string: ");
            fgets(str1, sizeof(str1), stdin);
            str1[strcspn(str1, "\n")] = '\0';
            printf("Enter character to search: ");
            scanf(" %c", &c);
            printf("Enter n: ");
            scanf("%d", &n);
            
            char *res = (char *)memchr(str1, c, n);
            if (res) {
                printf("Result: %s\n", res);
            } else {
                printf("Not found\n");
            }
            break;
        }

        case 'b': { // memcmp
            printf("Enter first string: ");
            fgets(str1, sizeof(str1), stdin);
            str1[strcspn(str1, "\n")] = '\0';
            printf("Enter second string: ");
            fgets(str2, sizeof(str2), stdin);
            str2[strcspn(str2, "\n")] = '\0';
            printf("Enter n: ");
            scanf("%d", &n);
            
            int result = memcmp(str1, str2, n);
            if (result == INVALID_INPUT) {
                printf("Error: Invalid input\n");
            } else if (result == SUCCESS) {
                printf("Strings are equal\n");
            } else {
                printf("Result: %d\n", result);
            }
            break;
        }

        case 'c': { // memcpy
            printf("Enter source string: ");
            fgets(str2, sizeof(str2), stdin);
            str2[strcspn(str2, "\n")] = '\0';
            printf("Enter n: ");
            scanf("%d", &n);
            
            void *res = memcpy(str1, str2, n);
            if (res) {
                str1[n] = '\0';
                printf("Copied: %s\n", str1);
            } else {
                printf("Error: Copy failed\n");
            }
            break;
        }

        case 'd': { // memset
            printf("Enter character to fill: ");
            scanf(" %c", &c);
            printf("Enter n: ");
            scanf("%d", &n);
            
            void *res = memset(str1, c, n);
            if (res) {
                str1[n] = '\0';
                printf("Result: %s\n", str1);
            } else {
                printf("Error: Memset failed\n");
            }
            break;
        }

        case 'e': { // strncat
            printf("Enter destination string: ");
            fgets(str1, sizeof(str1), stdin);
            str1[strcspn(str1, "\n")] = '\0';
            printf("Enter source string: ");
            fgets(str2, sizeof(str2), stdin);
            str2[strcspn(str2, "\n")] = '\0';
            printf("Enter n: ");
            scanf("%d", &n);
            
            char *res = strncat(str1, str2, n);
            if (res) {
                printf("Result: %s\n", str1);
            } else {
                printf("Error: Concatenation failed\n");
            }
            break;
        }

        case 'f': { // strchr
            printf("Enter string: ");
            fgets(str1, sizeof(str1), stdin);
            str1[strcspn(str1, "\n")] = '\0';
            printf("Enter character: ");
            scanf(" %c", &c);
            
            char *res = strchr(str1, c);
            if (res) {
                printf("Result: %s\n", res);
            } else {
                printf("Not found\n");
            }
            break;
        }

        case 'g': { // strncmp
            printf("Enter first string: ");
            fgets(str1, sizeof(str1), stdin);
            str1[strcspn(str1, "\n")] = '\0';
            printf("Enter second string: ");
            fgets(str2, sizeof(str2), stdin);
            str2[strcspn(str2, "\n")] = '\0';
            printf("Enter n: ");
            scanf("%d", &n);
            
            int result = strncmp(str1, str2, n);
            if (result == INVALID_INPUT) {
                printf("Error: Invalid input\n");
            } else if (result == SUCCESS) {
                printf("Strings are equal\n");
            } else {
                printf("Result: %d\n", result);
            }
            break;
        }

        case 'h': { // strncpy
            printf("Enter source string: ");
            fgets(str2, sizeof(str2), stdin);
            str2[strcspn(str2, "\n")] = '\0';
            printf("Enter n: ");
            scanf("%d", &n);
            
            char *res = strncpy(str1, str2, n);
            if (res) {
                str1[n] = '\0';
                printf("Copied: %s\n", str1);
            } else {
                printf("Error: Copy failed\n");
            }
            break;
        }

        case 'i': { // strcspn
            printf("Enter string: ");
            fgets(str1, sizeof(str1), stdin);
            str1[strcspn(str1, "\n")] = '\0';
            printf("Enter characters to match: ");
            fgets(str2, sizeof(str2), stdin);
            str2[strcspn(str2, "\n")] = '\0';
            
            size_t result = strcspn(str1, str2);
            if (result == INVALID_INPUT) {
                printf("Error: Invalid input\n");
            } else {
                printf("Result: %zu\n", result);
            }
            break;
        }

        case 'j': { // strerror
            printf("Enter error number: ");
            scanf("%d", &err);
            
            char *error_msg = strerror(err);
            printf("Error: %s\n", error_msg);
            break;
        }

        case 'k': { // strlen
            printf("Enter string: ");
            fgets(str1, sizeof(str1), stdin);
            str1[strcspn(str1, "\n")] = '\0';
            
            size_t result = strlen(str1);
            if (result == INVALID_INPUT) {
                printf("Error: Invalid input\n");
            } else {
                printf("Length: %zu\n", result);
            }
            break;
        }

        case 'l': { // strpbrk
            printf("Enter string: ");
            fgets(str1, sizeof(str1), stdin);
            str1[strcspn(str1, "\n")] = '\0';
            printf("Enter characters to search: ");
            fgets(str2, sizeof(str2), stdin);
            str2[strcspn(str2, "\n")] = '\0';
            
            char *res = strpbrk(str1, str2);
            if (res) {
                printf("Result: %s\n", res);
            } else {
                printf("Not found\n");
            }
            break;
        }

        case 'm': { // strrchr
            printf("Enter string: ");
            fgets(str1, sizeof(str1), stdin);
            str1[strcspn(str1, "\n")] = '\0';
            printf("Enter character: ");
            scanf(" %c", &c);
            
            char *res = strrchr(str1, c);
            if (res) {
                printf("Result: %s\n", res);
            } else {
                printf("Not found\n");
            }
            break;
        }

        case 'n': { // strstr
            printf("Enter string: ");
            fgets(str1, sizeof(str1), stdin);
            str1[strcspn(str1, "\n")] = '\0';
            printf("Enter substring: ");
            fgets(str2, sizeof(str2), stdin);
            str2[strcspn(str2, "\n")] = '\0';
            
            char *res = strstr(str1, str2);
            if (res) {
                printf("Result: %s\n", res);
            } else {
                printf("Not found\n");
            }
            break;
        }

        case 'o': { // strtok
            printf("Enter string (words separated by spaces): ");
            fgets(str1, sizeof(str1), stdin);
            str1[strcspn(str1, "\n")] = '\0';
            
            char *token = strtok(str1, " ");
            if (token) {
                while (token) {
                    printf("Token: %s\n", token);
                    token = strtok(NULL, " ");
                }
            } else {
                printf("No tokens found\n");
            }
            break;
        }

        default:
            printf("Invalid flag\n");
            break;
    }

    return SUCCESS;
}
