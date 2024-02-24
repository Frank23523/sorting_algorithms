#include "sort.h"

void swap_node_position(listint_t **head, listint_t **node1, listint_t *node2);

/**
 * insertion_sort_list - sorts dl list inascending order with Bubble sort
 * @list: A pointer to the head of a doubly-linked list of integers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted_node, *sorted_node, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (unsorted_node = (*list)->next; unsorted_node; unsorted_node = temp)
	{
		temp = unsorted_node->next;

		sorted_node = unsorted_node->prev;
		while (sorted_node != NULL && unsorted_node->n < sorted_node->n)
		{
			swap_node_position(list, &sorted_node, unsorted_node);
			print_list(*list);
		}
	}
}

/**
 * swap_node_position - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head
 * @node1: pointer to the first node to swap
 * @node2: pointer to the first node to swap
 */
void swap_node_position(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->next = *node1;

	node2->prev = (*node1)->prev;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;

	*node1 = node2->prev;
}
