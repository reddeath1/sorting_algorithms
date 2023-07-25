#include "sort.h"

/**
 * quick_sort - Main function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: The array
 * @size: The array size
 * Return: (void)
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sorts(array, 0, size - 1, size);
}

/**
 * quick_partition - Main function to quick partition for sort
 * @array: The array
 * @lo: The lower
 * @hi: The higher
 * @size: The array size
 * Return: (i)
 */
int quick_partition(int *array, int lo, int hi, size_t size)
{
	int i = lo - 1, j = lo;
	int pivot = array[hi], aux = 0;

	for (; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[hi])
	{
		aux = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = aux;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * sorts - Main quick sort function
 * @array: The array
 * @lower: The lower
 * @higher:The higher
 * @size: The array size
 * Return: (void)
 */
void sorts(int *array, int lower, int higher, size_t size)
{
	int pivot;

	if (lower < higher)
	{
		pivot = quick_partition(array, lower, higher, size);
		quick_s(array, lower, pivot - 1, size);
		quick_s(array, pivot + 1, higher, size);
	}
}
