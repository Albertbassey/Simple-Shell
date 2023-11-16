#include "shell.h"

/**
 * _strcat - catenates two(2) strings.
 * @dest: Destination str.
 *
 * @src: Origin str.
 *
 * Return: 0 Always.
 */

char *_strcat(char *dest, char *src)
{
	int j, k = 0;

	for (j = 0; dest[j] != '\0'; j++)
	{
	}
	for (k = 0; src[k] != '\0'; k++)
	{
		dest[j] = src[k];
		j++;

	}
	dest[j] = '\0';
return (dest);
}

/**
 * _strcmp - Compare two(2) strs
 *
 * @s1: a character str
 * @s2: another character str
 *
 * Return: multiple returns
 */

int _strcmp(char *s1, char *s2)
{
	int j = 0;
	int val;

	while (s1[j] != 0 && s2[j] != 0 && s1[j] == s2[j])
		j++;
val = s1[j] - s2[j];
return (val);

}

/**
 * _strlen - get size of the str.
 * @s: string to be measured.
 *
 * Return: length of a string.
 */

int _strlen(char *s)
{
	int j;

	for (j = 0; s[j] != 0; j++)
		;

	return (j);
}

/**
 *_strncmp -  function that compares two(2) strs.
 *@s1: a character str.
 *@s2: another character str.
 *@n: nos. of characters.
 * Return: diference
 */

size_t _strncmp(char *s1, char *s2, size_t n)
{
	size_t j, k;

	for (k = 0; s1[k] != '\0' && k < n; k++)
	{
		j = s1[k] - s2[k];

		if (j != 0)
		{
			return (j);
		}
	}
	return (0);
}

/**
 * _strcpy - copies the str pointed to src into dest.
 * @dest: copy destination.
 * @src: source.
 *
 * Return: char ptr to dest.
 */

char *_strcpy(char *dest, char *src)
{
	int j = 0;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[j] = src[j];
	}
	dest[j + 1] = 0;
	return (dest);
}
