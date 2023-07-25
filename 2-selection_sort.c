#include "sort.h"

/**
 * selection_sort - Main function that use selection sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 * Return: (Nothing).
 */
void selection_sort(int *array, size_t size)
{
	int a = 0;
	size_t i = 0, j = 0, position = 0;

	if (array == NULL || size == 0)
		return;

	for (; i < size - 1; i++)
	{
		position = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[position])
				position = j;
		}
		if (position != i)
		{
			a = array[i];
			array[i] = array[position];
			array[position] = a;
			print_array(array, size);
		}
	}
}
