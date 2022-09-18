#include "factors.h"

/**
 * remove_leading_zero - to remove leading zero in front of string
 * @string: user input string
 * Return: better string but must be freed
 *
 * Description: free new
 */
char *remove_leading_zero(char *string)
{
	char *new;
	unsigned int i = 0, j = 0, len_buffer = 0;

	len_buffer = strlen(string);
	for (i = 0, j = 0; string[i] == '0'; i++)
		;
	new = malloc(sizeof(char) * ((len_buffer - i) + 1));
	for (j = 0; string[i]; j++, i++)
		new[j] = string[i];
	new[j] = '\0';

	return (new);
}

/**
 * execute_command - the main brain behind the whole process
 *
 * @info: the info holder
 * Return: int 0 for success and unsigned int for line of failure
 */
int execute_command(all_info *info)
{
	unsigned int iter, iter2, iter3, prime, remainder, character;
	int result_str;
	user_input_t *user_command = info->input;
	char *buffer, *holder, *buff2;

	for (iter = 0; user_command; iter++, user_command = user_command->next)
	{
		buffer = user_command->command;
		for (prime = 2; 1;prime++)
		{
			if (prime != 2 && prime != 3 && prime != 5 && (prime % 5 == 0 || ((prime - 1) % 6 != 0 && (prime+1) % 6 != 0)))
				continue;
			holder = malloc(sizeof(char) *2);
			for (iter2 = 0, iter3 = 0, result_str = 0, remainder = 0; buffer[iter2] != '\0'; iter2++)
			{
				character = buffer[iter2] - '0';
				result_str *= 10;
				result_str += (character + (remainder*10)) / prime;
				if (result_str != 0 || iter2 > 0)
				{
					holder[iter3++] = (result_str % 10) + '0';
					holder = realloc(holder, iter3+1);
					result_str = 0;
				}
				remainder = (character + (remainder*10)) % prime;

			}
			holder[iter3] = '\0';
			if (remainder == 0)
				break;
			free(holder);
		}
		buff2 = remove_leading_zero(holder);
		printf("%s=%s*%d\n", buffer, buff2, prime);
		free(buff2);
	}
	return (0);
}
