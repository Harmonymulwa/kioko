#include <stdlib.h>
#include "main.h"

/**
 **_realloc -  Reallocates A Memory Block Using Malloc And Free
 *@ptr: Pointer
 *@old_size: Previous Size Of The Pointer
 *@new_size: New Size Of The Pointer
 *Return: Void Pointer Reallocated Memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size) {
    void *result;

    if (new_size == old_size)
        return (ptr);
    if (new_size == 0 && ptr) {
        free(ptr);
        return (NULL);
    }
    result = malloc(new_size);
    if (result == NULL)
        return (NULL);
    if (ptr == NULL) {
        fill_an_array(result, '\0', new_size);
        free(ptr);
    } else {
        _memcpy(result, ptr, old_size);
        free(ptr);
    }
    return (result);

}

/**
 * free_all - Free Array Of Char Pointer And Char Pointer
 * @cmd:Array Pointer
 * @line:Char Pointer
 * Return: Void
 */
void free_all(char **cmd, char *line) {
    free(cmd);
    free(line);
    cmd = NULL;
    line = NULL;
}

/**
 * _memcpy - Copy Byte From Source To Destination
 * @dest: Destination Pointer
 * @src: Source Pointer
 * @n: Size (How Much You Will Copy)
 *Return: Void Pointer
 */
char *_memcpy(char *dest, const char *src, unsigned int n) {
    unsigned int i;

    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    return (dest);
}

/**
 * fill_an_array - Fill An Array By Constant Byte
 * @a:Void Pointer
 * @num: number
 * @len:Length
 *Return: Void Pointer
 */
void *fill_an_array(void *a, int num, unsigned int len) {
    char *p = a;
    unsigned int i = 0;

    while (i < len) {
        *p = num;
        p++;
        i++;
    }
    return (a);
}

/**
 *  array_rev - Reverse Array
 * @arr:Array To Reverse
 * @len:Length Of Array
 * Return: Void(Reverse Array)
 */
void array_rev(char *arr, int len) {
    int i;
    char tmp;

    for (i = 0; i < (len / 2); i++) {
        tmp = arr[i];
        arr[i] = arr[(len - 1) - i];
        arr[(len - 1) - i] = tmp;
    }
}
