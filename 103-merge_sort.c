#include "sort.h"

/**
 * merge_arrays - merges two sorted subarrays into one
 * @array: array to be sorted
 * @buffer: buffer to store the merged subarrays
 * @front: start point of first subarray
 * @mid: end point of 1st subarray and start point of 2nd subarray
 * @back: end point of the second subarray.
 */
void merge_arrays(int *array, int *buffer,
		size_t front, size_t mid, size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + front, mid - front);

	printf("[right]: ");
	print_array(array + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buffer[k] = (array[i] < array[j]) ? array[i++] : array[j++];
	for (; i < mid; i++)
		buffer[k++] = array[i];
	for (; j < back; j++)
		buffer[k++] = array[j];
	for (i = front, k = 0; i < back; i++)
		array[i] = buffer[k++];

	printf("[Done]: ");
	print_array(array + front, back - front);
}

/**
 * merge_sort_recursive - uses recursion to merge sort a subarray
 * @array: array to sort.
 * @buffer: buffer to store intermediate results during sorting.
 * @front: start point of subarray.
 * @back: end point of subarray.
 */
void merge_sort_recursive(int *array, int *buffer, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(array, buffer, front, mid);
		merge_sort_recursive(array, buffer, mid, back);
		merge_arrays(array, buffer, front, mid, back);
	}
}

/**
 * merge_sort - sorts array inascending order with merge sort algorithm
 * @array: The array to sort.
 * @size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
