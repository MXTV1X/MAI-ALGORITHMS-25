#include "lab2.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test_my_memchr() {
    char str[] = "Hello World";
    
    char *result = my_memchr(str, 'o', 11);
    assert(result == &str[4]);
    
    result = my_memchr(str, 'z', 11);
    assert(result == NULL);
    
    printf("test_my_memchr: PASSED\n");
}

void test_my_memcmp() {
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";
    
    int result = my_memcmp(str1, str2, 5);
    assert(result == 0);
    
    result = my_memcmp(str1, str3, 5);
    assert(result < 0);
    
    printf("test_my_memcmp: PASSED\n");
}

void test_my_strlen() {
    size_t result = my_strlen("Hello");
    assert(result == 5);
    
    result = my_strlen("");
    assert(result == 0);
    
    printf("test_my_strlen: PASSED\n");
}

void test_my_strchr() {
    char str[] = "Hello World";
    
    char *result = my_strchr(str, 'o');
    assert(result == &str[4]);
    
    result = my_strchr(str, '\0');
    assert(result == &str[11]);
    
    result = my_strchr(str, 'z');
    assert(result == NULL);
    
    printf("test_my_strchr: PASSED\n");
}

void test_my_strstr() {
    char str[] = "Hello World";
    
    char *result = my_strstr(str, "World");
    assert(result == &str[6]);
    
    result = my_strstr(str, "xyz");
    assert(result == NULL);
    
    result = my_strstr(str, "");
    assert(result == str);
    
    printf("test_my_strstr: PASSED\n");
}

void test_my_strcspn() {
    char str1[] = "Hello World";
    char str2[] = "aeiou";
    
    size_t result = my_strcspn(str1, str2);
    assert(result == 1);
    
    result = my_strcspn("bcdfg", "aeiou");
    assert(result == 5);
    
    printf("test_my_strcspn: PASSED\n");
}

void test_my_strncmp() {
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";
    
    int result = my_strncmp(str1, str2, 5);
    assert(result == 0);
    
    result = my_strncmp(str1, str3, 5);
    assert(result < 0);
    
    printf("test_my_strncmp: PASSED\n");
}

void test_my_strerror() {
    char *result = my_strerror(0);
    assert(result != NULL);
    
    result = my_strerror(1);
    assert(result != NULL);
    
    result = my_strerror(999);
    assert(strcmp(result, "Unknown error") == 0);
    
    printf("test_my_strerror: PASSED\n");
}

void test_my_memory_functions() {
    char dest[20];
    char src[] = "Test";
    
    void *result = my_memcpy(dest, src, 4);
    assert(result == dest);
    assert(my_memcmp(dest, src, 4) == 0);
    
    result = my_memset(dest, 'A', 5);
    assert(result == dest);
    assert(dest[0] == 'A' && dest[4] == 'A');
    
    printf("test_my_memory_functions: PASSED\n");
}

void test_my_string_functions() {
    char dest[50] = "Hello ";
    char src[] = "World";
    
    char *result = my_strncat(dest, src, 5);
    assert(result == dest);
    assert(strcmp(dest, "Hello World") == 0);
    
    char dest2[20];
    result = my_strncpy(dest2, "Test", 10);
    assert(result == dest2);
    assert(strcmp(dest2, "Test") == 0);
    
    printf("test_my_string_functions: PASSED\n");
}

int main() {
    test_my_memchr();
    test_my_memcmp();
    test_my_strlen();
    test_my_strchr();
    test_my_strstr();
    test_my_strcspn();
    test_my_strncmp();
    test_my_strerror();
    test_my_memory_functions();
    test_my_string_functions();
    
    printf("\nAll tests passed successfully!\n");
    return 0;
}
