#include "sort.h"

/**
 * zero_init - Main Array initializeer by 0
 * @array: The array to be initialized
 * @size: The size of the array
 */
void zero_init(int *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
		array[i] = 0;
}

/**
 * _max - Main function to gets the maximum value in the array
 * @array: The array to get max value from
 * @size: The size of the array
 * Return: (maximum value)
 */
int _max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];

	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}

	return (max);
}

/**
 * _counter - main function that sort an array using the counting_sort
 * algorithm for LSD radix sort algorithm
 * @array: The initial array
 * @size: The size of the array
 * @place: (position of the LSD)
 */
void _counter(int *array, size_t size, int p)
{
	int k, *pos, *sum, *sort;
	size_t i, j;

	pos = malloc(sizeof(int) * 10);
	if (!pos)
		return;
	zero_init(pos, 10);

	for (i = 0; i < size; i++)
		pos[(array[i] / p) % 10] += 1;

	sum = malloc(sizeof(int) * 10);
	if (!sum)
		return;
	arr_zero_init(sum, 10);
	sum[0] = pos[0];

	for (j = 1; j < 10; j++)
		sum[j] = pos[j] + sum[j - 1];

	free(pos);

	sort = malloc(sizeof(int) * size);
	if (!sort)
		return;
	zero_init(sort, size);

	for (k = size - 1; k >= 0; k--)
	{
		sum[(array[k] / place) % 10] -= 1;
		sort[sum[(array[k] / p) % 10]] = array[k];
	}
	free(sum);

	for (i = 0; i < size; i++)
		array[i] = sort[i];
	free(sort);
}

/**
 * radix_sort - main function that least significant Digit
 * radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, pos = 1;

	if (!array || size < 2)
		return;

	max = _max(array, size);

	while ((max / pos) > 0)
	{
		sort_counter(array, size, pos);
		print_array(array, size);
		pos *= 10;
	}
}
