#include <stdio.h>
#include <unistd.h>

#include "sort.h"

/**
 * insertion_sort_list - sorts an list with insertion algo
 *
 *
 * @list: list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *ins;
	listint_t *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		ins = current->prev;

		while (ins != NULL && ins->n > current->n)
		{
			ins->next = current->next;
			if (current->next != NULL)
				current->next->prev = ins;
			current->prev = ins->prev;

			if (ins->prev != NULL)
				ins->prev->next = current;
			else
				*list = current;

			current->next = ins;
			ins->prev = current;
			print_list(*list);
			ins = current->prev;
		}
		current = next;
	}
}
