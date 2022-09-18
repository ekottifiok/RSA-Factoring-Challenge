#include "factors.h"

/**
 * read_file - reads what's inside a file
 *
 * @file_name: the file name to be read
 * @file_read: where to store the file that has being read
 * Return: int 0 for success and 1 for failure
 */
int read_file(char const *file_name, char **file_read)
{
	char c, *buffer;
	FILE *fp;
	unsigned int iter;

	fp = fopen(file_name, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", file_name);
		return (1);
	}
	buffer = malloc(sizeof(char));
	for (iter = 0; (c = fgetc(fp)) != EOF; iter++)
	{
		if (c == '$')
		{
			iter--;
			continue;
		}
		buffer[iter] = c;
		buffer = realloc(buffer, sizeof(char) * (iter + 2));
	}
	fclose(fp);
	buffer[iter] = '\0';
	*file_read = buffer;
	return (0);
}

/**
 * parse_read - reads the file and stores it in the all info
 *
 * @info: the location of the parsed data
 * Return: int 0 for success and 1 for failure
 */
int parse_read(all_info *info)
{
	char *read, *read_cp, *parsed;
	unsigned int iter;
	user_input_t *buffer_uin = NULL;

	if (read_file(info->file_name, &read))
		return (1);
	read_cp = read;
	parsed = strtok(read_cp, "\n");
	for (iter = 0; parsed; iter++)
	{
		add_node_end(&buffer_uin, remove_whitespace(parsed), iter + 1);
		parsed = strtok(NULL, "\n");
	}
	info->input = buffer_uin;
	free(read);
	return (0);
}

/**
 * initialize - initialize the all info data list
 *
 * @holder: the info list
 * @file: the name of the file
 * Return: int 0 for success and 1 for error
 */
int initialize(all_info *holder, char const *file)
{
	if (!holder)
		return (1);

	holder->file_name = file;
	return (0);
}

/**
 * main - the entrypoint of the whole program
 *
 * @argc: the number of variadic input
 * @argv: the list that carries the input
 * Return: int 0 for success and 1 for failure
 */
int main(int argc, char const *argv[])
{
	all_info data = INFO_INIT;

	if (argc != 2 && strcmp(*argv, "factors"))
	{
		printf("USAGE: factor file\n");
		exit(EXIT_FAILURE);
	}

	if (initialize(&data, argv[1]))
		return (1);
	if (parse_read(&data))
		exit(EXIT_FAILURE);
	execute_command(&data);
	free_all_info(&data);
	exit(EXIT_SUCCESS);
}
