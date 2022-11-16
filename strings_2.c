#include "main.h"
#include <stdlib.h>

/**
 * _isalpha - Check if Alphabetic
 *@c: Character
 * Return: 1 If True 0 If Not
 */
int _isalpha(int c) {
    if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90))) {
        return (1);
    } else {
        return (0);
    }
}

/**
 * _itoa - Convert Integer To Char
 * @n: Int To Convert
 * Return: Char Pointer
 */
char *_itoa(unsigned int n) {
    int len = 0, i = 0;
    char *s;

    len = num_len(n);
    s = malloc(len + 1);
    if (!s)
        return (NULL);
    *s = '\0';
    while (n / 10) {
        s[i] = (n % 10) + '0';
        n /= 10;
        i++;
    }
    s[i] = (n % 10) + '0';
    array_rev(s, len);
    s[i + 1] = '\0';
    return (s);
}

int _pow(int base, int exponent) {

    int ans = 1;

    while (exponent > 0) {

        int last_bit = (exponent & 1);

        if (last_bit) {
            ans *= base;
        }

        base *= base;
        exponent >>= 1;
    }

    return ans;
}

int _atoi(const char *str) {
    if (str == NULL) {
        return 0;
    }
    int j, i, n = 0, k = 1;
    char *tmp = _strdup(str);

    if (*str == '-') {
        *tmp = '0';
        k = -1;
    }
    i = _strlen(str);

    for (j = 0; j < i; ++j)
        n += (*(tmp + j) - '0') * _pow(10, i - j - 1);

    return n * k;
}

/**
 * num_len - Determine Length Of number
 * @num: Given Int
 * Return: Length Of Int
 */
int num_len(int num) {
    int len = 0;

    while (num != 0) {
        len++;
        num /= 10;
    }
    return (len);
}
