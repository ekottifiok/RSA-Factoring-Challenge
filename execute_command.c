#include "factors.h"

/**
 * execute_command - the main brain behind the whole process
 *
 * @info: the info holder
 * Return: int 0 for success and unsigned int for line of failure
 */
int execute_command(all_info *info)
{
	unsigned int iter, iter2, iter3, string_len, prime, remainder, character;
	int buffer_len, result_str;
	long *result;
	user_input_t *user_command = info->input;
	char *buffer, *holder;

	for (iter = 0; user_command; iter++, user_command = user_command->next)
	{
		buffer = user_command->command;
		string_len = strlen(buffer);
		for (prime = 2; 1;prime++)
		{
			holder = malloc(sizeof(char) *2);
			for (iter2 = 0, iter3 = 0, result_str = 0, remainder = 0; buffer[iter2] != '\0'; iter2++)
			{
				character = buffer[iter2] - '0';
				result_str *= 10;
				result_str += (character + remainder) / prime;
				if (result_str != 0 || iter2 > 0)
				{
					holder[iter3++] = (result_str % 10) + '0';
					holder = realloc(holder, iter3+1);
					result_str = 0;
				}
				remainder = (character % prime) * 10;
			}
			holder[iter3] = '\0';
			if (remainder == 0)
				break;
			free(holder);
		}
		printf("%s=%s*%d\n", buffer, holder, prime);
		free(holder);
	}
	return (0);
}
