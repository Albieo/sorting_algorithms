#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void merge_sort_recursion(int *array, int l, int r);
void merge_sorted_arrays(int *array, int l, int m, int r);

/**
 * merge_sort - function that sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 *
 * @array: The unsorted array.
 * @size: The size of the array.
*/
void merge_sort(int *array, size_t size)
{
	merge_sort_recursion(array, 0, size - 1);
}

/**
 * merge_sort_recursion - this function calls the recusively calls it self
 * and to sort the array than call a function to combine the nodes.
 *
 * @array: the array
 * @l: the left index in the split.
 * @r: the right index in the split.
*/
void merge_sort_recursion(int *array, int l, int r)
{
	int m;

	if (l < r)
	{
		m = l + (r - l) / 2;

		merge_sort_recursion(array, l, m);
		merge_sort_recursion(array, m + 1, r);

		merge_sorted_arrays(array, l, m, r);
	}
}

/**
 * merge_sorted_arrays - combines the sorted arrays.
 *
 * @array: The array with elements to be added.
 * @l: the left index.
 * @m: the middle point.
 * @r: the right index.
*/
void merge_sorted_arrays(int *array, int l, int m, int r)
{
	int left_length = m - l + 1;
	int right_length = r - m;
	int i, j, k;
	int *temp_left, *temp_right;

	temp_left = malloc(left_length * sizeof(int));
	if (temp_left == NULL)
		return;

	temp_right = malloc(right_length * sizeof(int));
	if (temp_right == NULL)
	{
		free(temp_left);
		return;
	}

	for (i = 0; i < left_length; i++)
		temp_left[i] = array[l + i];

	for (i = 0; i < right_length; i++)
		temp_right[i] = array[m + 1 + i];

	for (i = 0, j = 0, k = l; k <= r; k++)
	{
		if ((i < left_length) && (j >= right_length || temp_left[i] <= temp_right[j]))
		{
			array[k] = temp_left[i];
			i++;
		}
		else
		{
			array[k] = temp_right[j];
			j++;
		}
	}
	free(temp_left);
	free(temp_right);
}
