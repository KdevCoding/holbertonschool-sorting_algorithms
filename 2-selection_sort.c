#include <stdio.h>
#include <unistd.h>

#include "sort.h"

/**
 * selection_sort - sorts an array with selection_sort algo
 *
 * @size: size of array
 * @array: array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t ind;
	size_t min;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		ind = i + 1;
		while (ind < size)
		{
			if (array[ind] < array[min])
				min = ind;

			ind++;
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;

			print_array(array, size);
		}
		i++;
	}
}
