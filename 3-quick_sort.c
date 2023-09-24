#include "sort.h"

/**
 * swap - swaps two nodes in an array.
 * @a: the first array element.
 * @b: the second array element.
*/
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
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
    int i, j, pivot;

    pivot = high;
    i = low;
    j = high - 1;

    while (i <= j)
    {
        while (array[i] < array[pivot])
            i++;

        while (array[j] > array[pivot])
            j--;
        if (i <= j)
        {
            swap(&array[i], &array[j]);
            i++;
            j--;
        }
    }
    swap(&array[i], &array[pivot]);
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
    quick_sort_helper(array, 0, size - 1);
}

/**
 * quick_sort_helper - a helper function to start the algorithm.
 *
 * @array: the unsorted array.
 * @low: low index.
 * @high: high index.
*/
void quick_sort_helper(int *array, int low, int high)
{
    int pos;

    if (low < high)
    {
        pos = lomuto_partition(array, low, high);
        quick_sort_helper(array, low, pos - 1);
        quick_sort_helper(array, pos + 1, high);
    }
}