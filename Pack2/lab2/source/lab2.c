#include "lab2.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void *my_memchr(const void *str, int c, size_t n) {
    const unsigned char *mystr = str;
    for (size_t i = 0; i < n; i++) {
        if (mystr[i] == (unsigned char)c) {
            return (void*)(mystr + i);
        }
    }
    return NULL;
}

int my_memcmp(const void *str1, const void *str2, size_t n) {
    const unsigned char *mystr1 = str1;
    const unsigned char *mystr2 = str2;
    for (size_t i = 0; i < n; ++i) {
        if (mystr1[i] != mystr2[i]) {
            return mystr1[i] - mystr2[i];
        }
    }
    return 0;
}

void *my_memcpy(void *dest, const void *src, size_t n) {
    unsigned char *d = dest;
    const unsigned char *s = src;
    for (size_t i = 0; i < n; ++i) {
        d[i] = s[i];
    }
    return dest;
}

void *my_memset(void *str, int c, size_t n) {
    unsigned char *mystr = str;
    for (size_t i = 0; i < n; ++i) {
        mystr[i] = (unsigned char)c;
    }
    return str;
}

char *my_strncat(char *dest, const char *src, size_t n) {
    char *d = dest;
    while (*d) {
        d++;
    }
    size_t i = 0;
    while (i < n && *(src + i)) {
        *(d + i) = *(src + i);
        i++;
    }   
    *(d + i) = '\0';
    return dest;
}

char *my_strchr(const char *str, int c) {
    while (*str) {
        if (*str == (unsigned char)c) {
            return (char*)str;
        }
        str++;
    }
    return (c == '\0') ? (char*)str : NULL;
}

int my_strncmp(const char *str1, const char *str2, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0') {
            return (unsigned char)str1[i] - (unsigned char)str2[i];
        }
    }
    return 0;
}

char *my_strncpy(char *dest, const char *src, size_t n) {
    size_t i = 0;
    while (i < n && src[i] != '\0') {
        *(dest + i) = *(src + i);
        i++;
    }
    while (i < n) {
        *(dest + i) = '\0';
        i++;
    }
    return dest;
}

size_t my_strcspn(const char *str1, const char *str2) {
    size_t count = 0;
    while (*(str1 + count)) {
        for (const char *mystr2 = str2; *mystr2; mystr2++) {
            if (*(str1 + count) == *mystr2) {
                return count;
            }
        }
        ++count;
    }
    return count;
}

#ifdef __APPLE__
static const char *error_list[] = {
    "Undefined error: 0", "Operation not permitted", "No such file or directory",
    "No such process", "Interrupted system call", "I/O error"
};
#elif __linux__
static const char *error_list[] = {
    "Success", 
    "Operation not permitted", 
    "No such file or directory",
    "No such process", "Interrupted system call", "I/O error"
};
#else
static const char *error_list[] = { "Unknown OS" };
#endif

char *my_strerror(int errnum) {
    int max = sizeof(error_list) / sizeof(error_list[0]);
    if (errnum >= 0 && errnum < max) {
        return (char *)error_list[errnum];
    } else {
        return "Unknown error";
    }
}

size_t my_strlen(const char *str) {
    size_t len = 0;
    while (str[len]) len++;
    return len;
}

char *my_strpbrk(const char *str1, const char *str2) {
    while (*str1) {
        const char *mystr2 = str2; 
        while (*mystr2) {
            if (*str1 == *mystr2) {
                return (char *)str1; 
            }
            mystr2++; 
        }
        str1++;
    }
    return NULL;
}

char *my_strrchr(const char *str, int c) {
    const char *last_match = NULL; 
    while (*str) {
        if (*str == (char)c) {
            last_match = str; 
        }
        str++; 
    }
    if (c == '\0') {
        return (char *)str; 
    }

    return (char *)last_match; 
}

char* my_strstr(const char* str, const char *substr) {
    for (const char *s = str; *s; s++) {
        const char *h = s;
        const char *n = substr;
        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }
        if (!*n) {
            return (char*)s; 
        }
    }
    return NULL;
}

char *my_strtok(char *str, const char *delim) {
    static char *next;
    if (str) {
        next = str;
    }
    if (!next) {
        return NULL;
    }
    str = next + strspn(next, delim);
    if (*str == '\0') {
        return (next = NULL);
    }
    next = str + my_strcspn(str, delim);
    if (*next) {
        *next++ = '\0';
    }
    return str;
}
