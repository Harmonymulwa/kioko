#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strlen - calculate length of a string
 * @s: input string
 * Return: length of a string or 0 if string is NULL
 */
int _strlen(const char *s)
{
	int l = 0;

	if (!s)
		return (l);

	while (*s != '\0')
	{
		s++;
		l++;
	}
	return (l);
}

/**
* _strcmp - compares two strings
* @s1: first string
* @s2: second string
*
* Return: the difference of s1 and s2
*/
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (*(s1 + i) && *(s2 + i) && (*(s1 + i) == *(s2 + i)))
		i++;
	return (*(s1 + i) - *(s2 + i));
}

/**
 * _strcat - appends src string to the dest string
 * @dest: string to append by src
 * @src: string to append to dest
 *
 * Return: pointer to the resulting string dest,
 * or NULL if both strings are not present or NULL.
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	if (!dest && !src)
	{
		return (NULL);
	} else if (!dest)
	{
		return (src);
	} else if (!src)
	{
		return (dest);
	}
	i = j = 0;
	while (*(dest + i))
		i++;
	while ((*(dest + i) = *(src + j)))
	{
		i++;
		j++;
	}
	return (dest);
}

/**
 * _strncmp - Compare Amount (n) Of Characters Of Two Strings.
 * @s1: A String.
 * @s2: A String.
 * @n: Amount Of Characters To Compare.
 *
 * Return: 1 If The Strings Don't Match Otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (1);
	}
	return (0);
}

/**
 * *_strdup - copies a string given as parameter
 * @str: the string to be duplicated
 *
 * Return: pointer to the copied string (Success), NULL (Error)
 */
char *_strdup(const char *str)
{
	char *duplicate;
	unsigned int i, l;

	i = 0;
	l = _strlen(str);

	if (str == NULL)
		return (NULL);

	duplicate = malloc(sizeof(char) * (l + 1));

	if (duplicate == NULL)
		return (NULL);

	while ((duplicate[i] = str[i]) != '\0')
		i++;

	return (duplicate);
}

