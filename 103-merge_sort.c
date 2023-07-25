#include "sort.h"

/**
 * merge_sort - Main function that sorts array using merge algorithm.
 * @array: An array to sort.
 * @size: An size of the array.
 * Return: (Nothing).
 */
void merge_sort(int *array, size_t size)
{
	size_t i = 0;
	int *base = NULL;

	if (array == NULL || size < 2)
		return;
	base = malloc(sizeof(int) * size);
	if (base == NULL)
		return;
	for (; i < size; i++)
		base[i] = array[i];
	merge_partition(0, size, array, base);
	free(base);
}

/**
 * _merge - Main function that sort the sub arrays.
 * @lower: A Lower index.
 * @middle: A Middle index.
 * @higher: A Higher index.
 * @dest: The Destination for data.
 * @src: The Input data.
 * Return: (Nothing).
 */
void _merge(size_t lower, size_t middle, size_t higher, int *dest, int *src)
{
	size_t i = 0, j = 0, c = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + lower, middle - lower);
	printf("[right]: ");
	print_array(src + middle, higher - middle);
	i = lower;
	j = middle;
	c = lower;
		for (; c < higher; c++)
		{
			if (i < middle && (j >= higher || src[i] <= src[j]))
			{
				dest[c] = src[i];
				i++;
			}
			else
			{
				dest[c] = src[j];
				j++;
			}
		}
	printf("[Done]: ");
	print_array(dest + lower, higher - lower);
}

/**
 * _partition - Main funtion that splits the array recursively.
 * @lower: A Lower index.
 * @higher: A Higher index.
 * @array: The array to sort.
 * @base: A copy of the array.
 * Return: (Nothing).
 */
void _partition(size_t lower, size_t higher, int *array, int *base)
{
	size_t middle = 0;

	if (higher - lower < 2)
		return;
	middle = (lower + higher) / 2;
	_partition(lower, middle, array, base);
	_partition(middle, higher, array, base);
	merge(lower, middle, higher, array, base);
	for (middle = lower; middle < higher; middle++)
		base[middle] = array[middle];
}
