#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Function in C that inserts a number
 * into a sorted singly linked list.
 * @head: pointer to head of list
 * @number: number of items to insert_node
 * Return: listint_t*
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = NULL;
	listint_t *prev = NULL;
	listint_t *new;
	
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;

	if (*head == NULL || head == NULL)
	{
		new->next = NULL;
		*head = new;
		return (*head);
	}

	current = *head;
	prev = current;

	while (current != NULL)
	{
		if (current->n >= number)
			break;
		prev = current;
		current = current->next;
	}
	if (prev->n <= number)
	{
		prev->next = new;
		new->next = current;
	}
	if (prev->n > number)
	{
		*head = new;
		new->next = prev;
	}
	return (*head);
}
