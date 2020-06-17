#include "sort.h"

/**
 * shell_sort - sorts an array of integers with shell sorting
 *
 * @array: array
 * @size: size of the array
 * Return: Void
 */
void shell_sort(int *array, size_t size)
{
	size_t i = 0, gap = 1, pos = 0;
	int actual;

	if (size < 2 || !array)
		return;
	while (gap < size)
		gap = gap * 3 + 1;
	if (gap > size)
		gap = (gap - 1) / 3;
	while (gap > 0)
	{
		for (pos = 0; pos < size; pos++)
		{
			for (i = 0; i < size; i += gap)
			{
				if ((i + gap + pos) >= size)
					break;
				actual = i + pos;
				while (actual >= 0 && array[actual + gap] < array[actual])
				{
					swap_int(&array[actual + gap], &array[actual]);
					actual -= gap;
				}
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
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

