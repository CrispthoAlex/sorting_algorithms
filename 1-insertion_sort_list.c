#include "sort.h"

/**
 * insertion_sort_list - sorts a DLL of integers in ascending order
 *
 * @list: doubly linked list unsorted to be sorted
 *
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nodeprev = NULL, *current = NULL, *backup_current = NULL;
	listint_t *printlist = NULL;

	if (list == NULL || *list == NULL)
		return;
	current = *list; /* can we work with *list??? */
	printlist = *list;
	while (current)
	{
		nodeprev = current->prev;
		backup_current = current;
		while (nodeprev && nodeprev->n > current->n)
		{
			swap_node(nodeprev, current);
			while (printlist->prev != NULL)
				printlist = printlist->prev;
			print_list(printlist);
			nodeprev = current->prev;
		}
		current = backup_current->next;
	}
	while (printlist->prev != NULL)
		printlist = printlist->prev;
	*list = printlist;
}

/**
 * swap_node - swap two nodes of DLL
 * @prev: nodeprev to swap (up) with nodecurrent (down)
 * @current: nodecurrent (down) to swap with nodeprev (up)
 */
void swap_node(listint_t *prev, listint_t *current)
{
	listint_t *tmp1 = NULL, *tmp2 = NULL, *tmp3 = NULL;

	tmp1 = prev->prev;
	tmp2 = prev; /* Save nodes */
	tmp3 = current->next;

	prev->prev = current;
	prev->next = current->next;
	current->prev = tmp1;
	current->next = tmp2;
	if (tmp1)
		tmp1->next = current;
	if (tmp3)
		tmp3->prev = prev;
}
