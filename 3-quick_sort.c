#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partitions an array using the Lomuto partition scheme
 * @array: Array to partition
 * @size: Size of the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Final index of the pivot
 */
size_t lomuto_partition(int *array, size_t size, size_t low, size_t high)
{
	int pivot;
	size_t i, j;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		swap_ints(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_recursive - Recursively sorts an array using Lomuto quick sort
 * @array: Array to sort
 * @size: Size of the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void quick_sort_recursive(int *array, size_t size, size_t low, size_t high)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, size, low, high);

		if (pivot_index > low)
			quick_sort_recursive(array, size, low, pivot_index - 1);
		quick_sort_recursive(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *			   using the Quick sort algorithm (Lomuto partition scheme)
 * @array: Pointer to the array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, size - 1);
}
