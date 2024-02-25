#include "sort.h"

/**
 * counting_sort - sorts an array using the counting sort algorithm.
 * @array: array to be sorted.
 * @size: size of the array.
 * @exp: exponent indicating the digit to sort on.
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output, *count;
	size_t i, max = 10;

	output = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * max);
	if (output == NULL || count == NULL)
	{
		free(output);
		free(count);
		return;
	}

	for (i = 0; i < max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < max; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);

	free(output);
	free(count);
}

/**
 * radix_sort - sorts array inascending order with radix sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	size_t i;
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort(array, size, exp);
}
