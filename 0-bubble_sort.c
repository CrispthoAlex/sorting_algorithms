#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array unsorted to be sorted
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t pass = 0, offset = 0;

	if (!size || size < 2 || !array)
		return;

	for (; pass < size; pass++)
	{
		offset = 0;
		for (; offset < size - 1 - pass; offset++)
		{
			if (array[offset] > array[1 + offset])
			{
				swap_int(&array[offset], &array[1 + offset]);
				print_array(array, size);
			}
		}
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
