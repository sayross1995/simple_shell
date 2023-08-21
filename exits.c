#include "shell.h"

/**
 * custom_strncpy - Copies a string with a specified length limit.
 * @dest: The destination buffer.
 * @src: The source string to be copied.
 * @n: The maximum number of characters to copy.
 * Return: Pointer to the destination buffer.
 */
char *custom_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *result = dest;
	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (result);
}

/**
 * custom_strncat - Concatenates two strings with a specified length limit.
 * @dest: The destination buffer.
 * @src: The source string to be concatenated.
 * @n: The maximum number of characters to concatenate.
 * Return: Pointer to the destination buffer.
 */
char *custom_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *result = dest;
	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (result);
}

/**
 * custom_strchr - Locates a character in a string.
 * @s: The string to be searched.
 * @c: The character to locate.
 * Return: Pointer to the located character in the string.
 */
char *custom_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
	return (NULL);
}

