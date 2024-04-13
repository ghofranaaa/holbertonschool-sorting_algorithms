#include "sort.h"
/**
 * insertion_sort_list - sorting a doubly linked list of integers
 * in ascending order.
 * @list: pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nxt_n;
	listint_t *prv_n;
	listint_t *current;

if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	current = (*list)->next;
	while (current != NULL)
	{
		nxt_n = current->next;
		prv_n = current->prev;
		while (prv_n != NULL && prv_n->n > current->n)
		{
			if (prv_n->prev != NULL)
				prv_n->prev->next = current;
			if (current->next != NULL)
				current->next->prev = prv_n;

			current->prev = prv_n->prev;
			prv_n->prev = current;
			prv_n->next = current->next;
			current->next = prv_n;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);

			prv_n = current->prev;
		}
		current = nxt_n;
	}
}
