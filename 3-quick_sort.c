#include "sort.h"

/**
 * lomuto_partition - Partitions a subarray of an array of integers
 * using the Lomuto partition scheme (last element as pivot).
 * @array: int array
 * @size: array size
 * @low: The starting index
 * @high: The ending index
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot;
	int i;
	int j;
	int temp;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] != array[high])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_recursive - Recursively sorts a subarray using the
 * quick sort algorithm with the Lomuto partition scheme.
 * @array: int array
 * @size: array size
 * @low: The starting index
 * @high: The ending index
 */
void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int part;

	if (low < high)
	{
		part = lomuto_partition(array, size, low, high);

		quick_sort_recursive(array, size, low, part - 1);
		quick_sort_recursive(array, size, part + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the quick sort algorithm (Lomuto partition scheme)
 *
 * @array: int array
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, (int)size - 1);
}
