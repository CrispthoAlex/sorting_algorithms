#include "sort.h"


/**
 * selection_sort - Sorts an array using selection technique
 * @array: array to be sorted
 * @size: length of array
 */
void selection_sort(int *array, size_t size)
{
	size_t offset = 0;
	size_t i, min_pos = 0;

	if (!array || size < 2)
		return;
	while (offset < size - 1)
	{
		min_pos = offset;
		for (i = offset; i < size; i++)
		{
			if (array[i] < array[min_pos])
			{
				min_pos = i;
			}
		}
		if (offset != min_pos)
		{
			swap_int(&array[offset], &array[min_pos]);
			print_array(array, size);
		}
		offset++;
	}
}


/**
 * swap_int -  swap two values/int
 * @value1: value 1 to swap with value 2
 * @value2: value 2 to swap with value 1
 */
void swap_int(int *value1, int *value2)
{
	*value1 = *value1 ^ *value2;
	*value2 = *value2 ^ *value1;
	*value1 = *value1 ^ *value2;
}

