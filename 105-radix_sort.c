#include "sort.h"

/**
 * find_max - finds the maximum value in an array of ints
 * @array: array of ints
 * @size: size of the array.
 *
 * Return: maximum integer
 */
int find_max(int *array, int size)
{
	int max_value = array[0];
	int i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	return (max_value);
}

/**
 * counting_sort - sort the significant digits using counting sort algorithm.
 * @array: array of ints
 * @size: size of the array
 * @sig: digit position
 * @buff: buffer to store the sorted array
 */
void counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - sorts array inascending order with radix sort algorithm
 * @array: array of ints
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int *buffer, max_value, digit;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	max_value = find_max(array, size);

	for (digit = 1; max_value / digit > 0; digit *= 10)
	{
		counting_sort(array, size, digit, buffer);
		print_array(array, size);
	}

	free(buffer);
}
