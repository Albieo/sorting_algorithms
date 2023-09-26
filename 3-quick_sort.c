#include "sort.h"

void swap(int *x, int *y);
void quick_sort(int *array, size_t size);
void quick_sort_recursion(int *array, int low, int high);
int lomuto_partition(int *array, int low, int high);

/**
 * swap - swaps two nodes in an array.
 * @x: the first array element.
 * @y: the second array element.
*/
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * lomuto_partition - partition scheme used to swap elements.
 * @array: the unsorted array.
 * @low: low index.
 * @high: high index.
 *
 * Return: Index of the low swapped node.
*/
int lomuto_partition(int *array, int low, int high)
{
	int pivot_value = array[high];
	int i, j;

	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);

	return (i);
}

/**
 * quick_sort -  a function that sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 *
 * @array: The unsorted array.
 * @size: The size of the array.
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_recursion(array, 0, size - 1);
}

/**
 * quick_sort_recursion - a helper function to start the algorithm.
 *
 * @array: the unsorted array.
 * @low: low index.
 * @high: high index.
*/
void quick_sort_recursion(int *array, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high);
		quick_sort_recursion(array, low, pivot_index - 1);
		quick_sort_recursion(array, pivot_index + 1, high);
	}
}
