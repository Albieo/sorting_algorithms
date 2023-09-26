#include "sort.h"

/**
 * counting_sort - a function that sorts an array of integers in
 * ascending order using the Counting sort algorithm.
 *
 * @array: The unsorted array.
 * @size: The size of the array.
*/
void counting_sort(int *array, size_t size)
{
	size_t i, j, k = 0;
	size_t *count;
	int *output;

	for (i = 0; i < size; i++)
	{
	if ((size_t)array[i] > k)
		k = array[i];
	}

	count = (size_t *)malloc((k + 1) * sizeof(size_t));
	if (count == NULL)
	return;

	for (i = 0; i <= k; i++)
	count[i] = 0;

	for (i = 0; i < size; i++)
	count[array[i]]++;

	for (i = 1; i <= k; i++)
	count[i] += count[i - 1];

	output = (int *)malloc(size * sizeof(int));
	if (output == NULL)
	{
	free(count);
	return;
	}

	for (i = size - 1; i > 0; i--)
	{
	j = array[i];
	output[count[j] - 1] = j;
	count[j]--;
	}

	for (i = 0; i < size; i++)
	array[i] = output[i];
	free(output);
	free(count);
}
