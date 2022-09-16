#include "factors.h"

/**
 *  _strdup - Duplicates a string
 * @str: The string
 *
 * Return: The duplicate
 */
char *_strdup(char *str)
{
	char *dup;

	if (str == NULL)
		return (NULL);

	dup = malloc(sizeof(char) * _strlen(str) + 1);
	if (dup == NULL)
		return (NULL);
	dup = _strcpy(dup, str);
	return (dup);
}

/**
 * remove_whitespace - to remove whitespace in front of string
 * @string: user input string
 * Return: better string but must be freed
 *
 * Description: free new
 */
char *remove_whitespace(char *string)
{
	char *new;
	unsigned int i = 0, j = 0, len_buffer = 0;

	len_buffer = strlen(string);
	for (i = 0, j = 0; string[i] == ' '; i++)
		;
	new = malloc(sizeof(char) * ((len_buffer - i) + 1));
	for (j = 0; string[i]; j++, i++)
		new[j] = string[i];
	new[j] = '\0';

	return (new);
}
