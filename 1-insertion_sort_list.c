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

	if (list == NULL || *list == NULL || (*list->next == NULL))
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
			prv_n = prv_n->prev;
		}
		if (prv_n == NULL)
		{
			current = nxt_n;
		}
		if (current->next != NULL)
		{
			current->next->prev = current->prev;
		}
		current->prev->next = current->next;
		if (prv_n != NULL)
		{
			prv_n->next->prev = current;
		}
		current->next = prv_n->next;
		prv_n->next = current;
		current->prev = prv_n;
		if (current->prev == NULL)
		{
			*list = current;
		}
		print_list(*list);
		current = nxt_n;
	}
}
