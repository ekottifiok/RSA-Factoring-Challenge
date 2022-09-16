#include "factors.h"


/**
 * copy_string_index - copies a string based on the index
 * either a character or index
 * @string: the string to be copied
 * @start: the index to start
 * @find: the character to start the copy
 * Return: it returns a copy of the string
 */
char *copy_string_index(char *string, unsigned int start, char *find)
{
	size_t iter, size_string, diff;
	char *buffer;

	size_string = strlen(string);
	if ((!start && !find) || start >= size_string)
		return (NULL);
	if (find)
	{
		for (iter = 0; iter < size_string; iter++)
		{
			if (string[iter] == *find)
			{
				if (string[iter + 1] == *find)
					continue;
				break;
			}
		}
		if (iter == size_string)
			return (NULL);
		start += iter;
	}
	diff = size_string - start;
	buffer = malloc(sizeof(char) * (diff + 1));
	for (iter = 0; iter < diff; iter++, start++)
	{
		buffer[iter] = string[start];
	}
	buffer[iter] = '\0';

	return (buffer);
}


/**
 * _strncmp - compares two strings and returns the difference
 * @s1: string one
 * @s2: string two
 * @len: expected len of string
 * Return: the difference in string
 */
int _strncmp(char *s1, char *s2, int len)
{
	int a;


	for (a = 0; s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0'; a++)
		;
	if (a == len)
		return (0);
	return (-1);
}


/**
 * _strlen - returns the length of a string.
 * @s: The string to compute the length
 *
 * Return: int
 */
int _strlen(char *s)
{
	int len = 0, i;

	for (i = 0; s[i] != '\0'; i++)
		len++;

	return (len);
}


/**
 * _strcpy -  copies a string.
 * @src: the string to be copied from
 * @dest: the string to be copied to
 *
 * Return: A pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * _strcmp - compares two strings and returns the difference
 * @s1: string one
 * @s2: string two
 * Return: the difference in string
 */
int _strcmp(char *s1, char *s2)
{
	int a;

	a = 0;

	if (_strlen(s1) != _strlen(s2))
		return (-1);
	while (s1[a] != '\0' || s2[a] != '\0')
	{
		if (s1[a] != s2[a])
			return (-1);
		a++;
	}
	return (0);
}
