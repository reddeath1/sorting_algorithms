#include "sort.h"

/**
 * _swap - Main function to swap the nodes in a list
 * @list: The first node in doubly linked list
 * @first: The address of first node
 * @second: The address of second node
 */
void _swap(listint_t **list, listint_t *f, listint_t *s)
{
	if (!f->prev)
		*list = s;
	else
		f->prev->next = s;

	s->prev = f->prev;

	if (s->next)
		s->next->prev = f;


	f->prev = s;
	f->next = s->next;
	s->next = f;
}

/**
 * cocktail_sort_list - Main function of the cocktail sort algorithm
 * to sort numbers
 * @list: The first node of doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *f;
	int swap = 1;

	if (!list || !(*list) || !(*list)->next)
		return;

	f = *list;
	while (swap)
	{
		swap = 0;
		while (f->next)
		{
			if (f->n > f->next->n)
			{
				_swap(list, f, f->next);
				print_list(*list);
				swap = 1;
				continue;
			}
			f = f->next;
		}

		if (!swap)
			break;

		swap = 0;
		while (f->prev)
		{
			if (f->n < f->prev->n)
			{
				_swap(list, f->prev, f);
				print_list(*list);
				swap = 1;
				continue;
			}
			f = f->prev;
		}
	}
}
