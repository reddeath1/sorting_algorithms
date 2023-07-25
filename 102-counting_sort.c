#include "sorts.h"

/**
  * counting_sort - Main Afunction that sort an array using counting algorithm.
  * @array: An array to sort.
  * @size: An length of the array.
  * Return: (Nothing).
  */
void counting_sort(int *array, size_t size)
{
	unsigned int i = 1;
	int *count = NULL, c = 0, j = 0;

	if (array == NULL || size < 2)
		return;

	c = array[0];
	for (; i < size; i++)
	{
		if (array[i] > k)
			c = array[i];
	}

	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;

	for (j = 0; j <= c; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	for (j = 0; j < c; j++)
	{
		count[j + 1] += count[j];
		printf("%d, ", count[j]);
	}
	count[j + 1] += count[j];
	printf("%d\n", count[j + 1]);
	for (i = 0; i < size; i++)
	{
		j = count[array[i]] - 1;
		if (array[i] != array[j])
		{
			c = array[i];
			array[i] = array[j];
			array[j] = c;
		}
	}
	free(count);
}
