#include "factors.h"

/**
 * add_node_end - add a node to the end
 *
 * @head: the pointer to the head pointer
 * @str: the new str
 * @line_num: the new line number
 * Return: list_t*
 */
user_input_t *add_node_end(user_input_t **head, char *str, int line_num)
{
	user_input_t *newNode, *buffer;

		newNode = malloc(sizeof(user_input_t));
	if (!newNode)
		return (NULL);
	newNode->line_number = line_num;
	newNode->command = str;
	newNode->next = NULL;
	buffer = *head;

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		while (buffer->next)
		{
			buffer = buffer->next;
		}
		buffer->next = newNode;
	}

	return (newNode);
}
