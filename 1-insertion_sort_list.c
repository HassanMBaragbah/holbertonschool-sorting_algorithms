#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list.
 * @list: Pointer to the head of the list.
 * @node1: Pointer to the left node.
 * @node2: Pointer to the right node.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;

	node2->prev = node1->prev;
	node2->next = node1;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	node1->prev = node2;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *					   in ascending order using Insertion sort.
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		tmp = current;
		current = current->next;

		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			swap_nodes(list, tmp->prev, tmp);
			print_list(*list);
		}
	}
}
