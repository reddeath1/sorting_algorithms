#include "sort.h"

/**
  * shell_sort - Main function that sort an array using shell algorithm.
  * @array: An array to sort.
  * @size: An length of the array.
  * Return: (Nothing).
  */
void shell_sort(int *array, size_t size)
{
	unsigned int i = 0, j = 0, gap = 0;
	int a = 0;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			a = array[i];
			for (j = i; j >= gap && array[j - gap] > a;
					j -= gap)
			{
				if (array[j] != array[j - gap])
					array[j] = array[j - gap];
			}
			if (array[j] != a)
				array[j] = a;

		}
		print_array(array, size);
	}
}
