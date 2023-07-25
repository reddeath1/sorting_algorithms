#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * counting_sort - main function that sort an array using counting algorithm.
  * @array: The array to sort.
  * @size: The length of the array.
  * Return: (Nothing).
  */
void counting_sort(int *array, size_t size)
{
	unsigned int i = 1;
	int *c = NULL, k = 0, j = 0;

	if (array == NULL || size < 2)
		return;

	k = array[0];
	for (; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	c = malloc(sizeof(int) * (k + 1));
	if (c == NULL)
		return;

	for (j = 0; j <= k; j++)
		c[j] = 0;
	for (i = 0; i < size; i++)
		c[array[i]] += 1;
	for (j = 0; j < k; j++)
	{
		c[j + 1] += c[j];
		printf("%d, ", c[j]);
	}
	c[j + 1] += c[j];
	printf("%d\n", c[j + 1]);
	for (i = 0; i < size; i++)
	{
		j = c[array[i]] - 1;
		if (array[i] != array[j])
		{
			k = array[i];
			array[i] = array[j];
			array[j] = k;
		}
	}
	free(c);
}
