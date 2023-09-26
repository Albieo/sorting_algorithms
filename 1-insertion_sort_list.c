#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: The unsorted linked list.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *current = *list;
	listint_t *next, *temp;

	if (*list == NULL || (*list)->next == NULL)
		return;

	while (current)
	{
		next = current->next;

		if (sorted == NULL || current->n <= sorted->n)
		{
			current->next = sorted;
			current->prev = NULL;

			if (sorted)
				sorted->prev = current;

			sorted = current;
		}
		else
		{
			temp = sorted;
			while (temp->next && temp->next->n < current->n)
				temp = temp->next;

			current->next = temp->next;
			current->prev = temp;

			if (temp->next)
				temp->next->prev = current;

			temp->next = current;
		}
		current = next;
	}
	*list = sorted;
}
