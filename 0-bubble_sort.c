#include "sort.h"

/**
 * bubble_sort - sorts array inascending order with Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap_counter;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swap_counter = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap_counter = 1;
				print_array(array, size);
			}
		}

		if (swap_counter == 0)
			break;
	}
}
