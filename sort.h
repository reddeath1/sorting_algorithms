#ifndef __SORT__
#define __SORT__

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "deck.h"

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void partition_merger(size_t lower, size_t higher, int *array, int *base);
int quick_partition(int *array, int lower, int higher, size_t size);
void _merge(size_t lower, size_t middle, size_t higher, int *dest, int *src);
void _partition(size_t lower, size_t higher, int *array, int *base);
void sorts(int *array, int lower, int higher, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void sort_deck(deck_node_t **deck);

#endif /* __SORT__ */
