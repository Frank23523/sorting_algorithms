#include "sort.h"

/**
 * selection_sort - sorts array inascending order with selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_value;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_value = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_value])
				min_value = j;
		}

		if (min_value != i)
		{
			temp = array[i];
			array[i] = array[min_value];
			array[min_value] = temp;
			print_array(array, size);
		}
	}
}
