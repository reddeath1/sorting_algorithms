#include "sort.h"

/**
 * _swap - Main function that swap the root nodes.
 * @array:  heap to sort.
 * @root:  root of the heap.
 * @higher: higher index.
 * @size: size of the array.
 * Return: (Nothing)
 */
void swap_root(int *array, size_t root, size_t higher, size_t size)
{
	size_t lower = 0, middle = 0, tmp = 0;
	int a = 0;

	while ((lower = (2 * root + 1)) <= higher)
	{
		tmp = root;
		middle = lower + 1;
		if (array[tmp] < array[lower])
			tmp = lower;
		if (middle <= higher && array[tmp] < array[middle])
			tmp = middle;
		if (tmp == root)
			return;
		a = array[root];
		array[root] = array[tmp];
		array[tmp] = a;
		print_array(array, size);
		root = tmp;
	}
}

/**
 * heap_sort - Main function that sort an array using heap algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 * Return: (Nothing).
 */
void heap_sort(int *array, size_t size)
{
	size_t higher = 0, gap = 0;
	int tmp = 0;

		if (array == NULL || size < 2)
			return;

		for (gap = (size - 2) / 2; 1; gap--)
		{
			_swap(array, gap, size - 1, size);
			if (gap == 0)
				break;
		}

		higher = size - 1;
		while (higher > 0)
	{
		tmp = array[higher];
		array[higher] = array[0];
		array[0] = tmp;
		print_array(array, size);
		higher--;
		_swap(array, 0, higher, size);
	}
}
