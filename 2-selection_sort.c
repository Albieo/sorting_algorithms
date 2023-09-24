#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: The unsorted array.
 * @size: The size of the array.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		temp = array[min];
		array[min] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}
