#include "sort.h"

/**
 * swap - swaps two ints in an array.
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
 * hoare_partition - Partition a subset of an array of integers
 *                   according to the Hoare partition scheme.
 * @array: array of ints
 * @size: size of the array
 * @left: start point of the subset to partition
 * @right: end point of the subset to partition
 *
 * Return: final partition index
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_recursive - quicksort with recursion using Hoare partition scheme.
 * @array: array of ints to sort
 * @size: size of the array
 * @left: start point of the array partition to sort
 * @right: end point of the array partition to sort
 */
void hoare_recursive(int *array, size_t size, int left, int right)
{
	int partition_index;

	if (right - left > 0)
	{
		partition_index = hoare_partition(array, size, left, right);
		hoare_recursive(array, size, left, partition_index - 1);
		hoare_recursive(array, size, partition_index, right);
	}
}

/**
 * quick_sort_hoare - sorts array inascending order
 * with quicksort algorithm with the Hoare partition scheme
 * @array: array of ints
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_recursive(array, size, 0, size - 1);
}
