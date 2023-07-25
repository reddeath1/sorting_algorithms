#include "sort.h"

/**
 * sequence_printer - Main function that prints an array
 * @array: The array
 * @lower: The lower boundary
 * @higher: The higher boundary
 */
void sequence_printer(int *array, int lower, int higher)
{
	char *sp;

	for (sp = ""; lower <= higher; lower++)
	{
		printf("%s%d", sep, array[lower]);
		sp = ", ";
	}
	printf("\n");
}

/**
 * dir_swap - Main function that swaps two elements if they are in the
 * specified bitonic direction
 * @array: The array
 * @first: The first element
 * @second: The second element
 * @dir: The direction 1 for UP and 0 for DOWN
 */
void dir_swap(int *array, int first, int second, int dir)
{
	int tmp;

	if (dir == (array[first] > array[second]))
	{
		tmp = array[e1];
		array[first] = array[second];
		array[second] = tmp;
	}
}

/**
 * sequence_merger -Main function that merge sequence bitonically
 * @array: The array
 * @lower: The lower boundary
 * @higher: The high boundary
 * @dir: direction 1 for up and 0 for down
 * @size: (array size)
 */
void merge_sequence(int *array, size_t lower, size_t higher, int dir, size_t size)
{
	size_t middle, i, j;

	if (higher - lower < 1)
		return;

	middle = (lower + higher) / 2;
	for (i = lower, j = middle + 1; i <= middle; i++, j++)
		dir_swap(array, i, j, dir);

	sequence_merger(array, lower, middle, dir, size);
	sequence_merger(array, middle + 1, higher, dir, size);
}

/**
 * sequence_maker - main function that  makes bitonic sequence
 * @array: the array
 * @lower: lower boundary
 * @higher: high boundary
 * @dir: The direction 1 for up and 0 for down
 * @size: array size
 */
void make_sequence(int *array, size_t lower, size_t higher, int dir, size_t size)
{
	char *dirr;
	size_t middle;

	if (higher - lower < 1)
		return;

	dirr = dir ? "UP" : "DOWN";
	printf("Merging [%ld/%ld] (%s):\n", higher - lower + 1, size, direction);
	sequence_printer(array, lower, higher);

	middle = (lower + higher) / 2;
	sequence_maker(array, lower, middle, 1, size);
	sequence_maker(array, middle + 1, high, 0, size);

	sequence_merger(array, lower, higher, dir, size);
	printf("Result [%ld/%ld] (%s):\n", higher - lower + 1, size, dirr);
	sequence_printer(array, lower, higher);
}

/**
 * bitonic_sort - Main function that sorts an array of integers in
 * ascending order using the Bitonic sort algorithm
 * @array: The array
 * @size: The array size
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	sequence_maker(array, 0, size - 1, 1, size);
}
