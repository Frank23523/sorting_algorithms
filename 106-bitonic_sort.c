#include "sort.h"

/**
 * swap - swaps two ints
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * merge_sequence - merge a bitonic sequence inside an array of ints
 * @array: array of ints
 * @size: size of the array
 * @start: start point of the sequence in array to sort
 * @seq: size of the sequence to sort
 * @direction: direction to sort in
 */
void merge_sequence(int *array, size_t size, size_t start, size_t seq,
		char direction)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((direction == UP && array[i] > array[i + jump]) ||
			    (direction == DOWN && array[i] < array[i + jump]))
				swap(array + i, array + i + jump);
		}
		merge_sequence(array, size, start, jump, direction);
		merge_sequence(array, size, start + jump, jump, direction);
	}
}

/**
 * build_sequence - convert an array of ints into a bitonic sequence
 * @array: array of ints
 * @size: size of array
 * @start: start point of a block of the building bitonic sequence
 * @seq: size of a block of the building bitonic sequence
 * @direction: direction to sort the bitonic sequence block in
 */
void build_sequence(int *array, size_t size, size_t start,
		size_t seq, char direction)
{
	size_t cut = seq / 2;
	char *str = (direction == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		build_sequence(array, size, start, cut, UP);
		build_sequence(array, size, start + cut, cut, DOWN);
		merge_sequence(array, size, start, seq, direction);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - sorts array inascending order with bitonic sort algorithm
 * @array: array of ints
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	build_sequence(array, size, 0, size, UP);
}
