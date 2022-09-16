#include "factors.h"

/**
 * _pow_recursion - finds the power of number using recursion
 * @x: the base value example 10
 * @y: the power example 2
 * Return: returns the value of 10**2 which is 100
 */
long _pow_recursion(unsigned int x, long y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}

/**
 * str_to_integer - converts string to integer
 *
 * @s: the string to be converted
 * Return: long of the result
 */

/**
 * str_to_integer - converts string to integer
 *
 * @s: the string to be converted
 * Return: long of the result
 */
long str_to_integer(char *s)
{
	unsigned int i, factor;
	long digit;

	if (!s)
		return (-1);
	
	for (factor = 0, i = 0; s[i] && (s[i] >= '0' && s[i] <= '9'); i++, factor++)
	;
	for (i = 0, digit = 0, factor--; s[i]; i++, factor--)
	{
		if (s[i] < '0' || s[i] > '9')
			return (digit);
		digit += STR_TO_INT(s[i]) * _pow_recursion(10, factor);
	}
	return (digit);
}

long *factor(char *str)
{
	long *value, buffer, str_convert;

	value = malloc(sizeof(long) * 4);
	str_convert = str_to_integer(str);
	value[0] = str_convert;
	for (buffer = 2; str_convert % buffer != 0 && str_convert > buffer;)
		buffer++;
	value[1] = str_convert / buffer;
	value[2] = buffer;
	value[3] = 0;
	return value;
}

/**
 * execute_command - the main brain behind the whole process
 *
 * @info: the info holder
 * Return: int 0 for success and unsigned int for line of failure
 */
int execute_command(all_info *info)
{
	unsigned int iter;
	long *result;
	user_input_t *user_command = info->input;

	for (iter = 0; user_command; iter++, user_command = user_command->next)
	{
		result = factor(user_command->command);
		printf("%ld=%ld*%ld\n", result[0], result[1], result[2]);
	}
	return (0);
}
