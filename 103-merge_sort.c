#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - Main function that sorts an array using merge algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
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
	partition_merger(0, size, array, base);
	free(base);
}

/**
 * merger - Main function that sorts the subarrays.
 * @lower: Lower index.
 * @middle: Middle index.
 * @higher: Higher index.
 * @dest: The Destination for data.
 * @src: The Input data.
 * Return: (Nothing)
 */
void merger(size_t lower, size_t middle, size_t higher, int *dest, int *src)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + lower, middle - lower);
	printf("[right]: ");
	print_array(src + middle, higher - middle);
	i = lower;
	j = middle;
	k = lower;
		for (; k < higher; k++)
		{
			if (i < middle && (j >= higher || src[i] <= src[j]))
			{
				dest[k] = src[i];
				i++;
			}
			else
			{
				dest[k] = src[j];
				j++;
			}
		}
	printf("[Done]: ");
	print_array(dest + lower, higher - lower);
}

/**
 * merge_partition - A funtion that splits the array recursively.
 * @lo: Lower index.
 * @hi: Higher index.
 * @array: The array to sort.
 * @base: The copy of the array.
 * Return: Nothing.
 */
void partition_merger(size_t lower, size_t higher, int *array, int *base)
{
	size_t middle = 0;

	if (higher - lower < 2)
		return;
	middle = (lower + higher) / 2;
	partition_merger(lower, middle, array, base);
	partition_merger(middle, higher, array, base);
	merger(lower, middle, higher, array, base);
	for (middle = lower; middle < higher; middle++)
		base[middle] = array[middle];
}
