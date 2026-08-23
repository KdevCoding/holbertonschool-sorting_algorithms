#include <stdio.h>
#include <unistd.h>

#include "sort.h"

/**
 * bubble_sort - sorts an array with bubble algo
 *
 * @size: size of array
 * @array: array
 *
 */
void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i;
	int temp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 1;
		while (i < size)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				swapped = 1;

				print_array(array, size);
			}

			i++;
		}
	}
}
