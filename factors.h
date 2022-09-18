#ifndef FACTORS_H
#define FACTORS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#if __STDC_VERSION__ >= 199901L
#include <inttypes.h>
#else
#define PRIu16 "hu"
#endif

/* custom definitions */
#define STR_TO_INT(val) (val - 48)
#define INT_TO_STR(val) (val + 48)
#define LONG_MAX (9223372036854775807)
#define LONG_WIDTH 18

/**
 * struct user_input_s - linked list of the user inputs
 *
 * @line_number: the line number of the command
 * @command: the actual command inputted by the user
 * @next: the next available command
 *
 * Description: all user input is stored in this list
 */
typedef struct user_input_s
{
	int line_number;
	char *command;
	struct user_input_s *next;
} user_input_t;

/**
 * struct info_s - carries all the instruction
 * @file_name: the file the user opens
 * @input: the user input list
 */
typedef struct info_s
{
	user_input_t *input;
	char const *file_name;
} all_info;

#define INFO_INIT 			\
	{							\
		NULL, NULL			\
	}

int execute_command(all_info *info);
user_input_t *add_node_end(user_input_t **head, char *str, int line_num);
int free_all_info(all_info *info);

char *remove_whitespace(char *string);
int _strcmp(char *, char *);
char *_strdup(char *);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, int len);
char *copy_string_index(char *, unsigned int, char *);
char *remove_whitespace(char *string);

#endif
