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
	size_t pass = 0, gap = 1;
	unsigned int offset = 0, multiplier = 0;

	if (size < 2 || !array)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;
		for (pass = 0; pass < gap; pass++)
		{
			if (pass != 0)
				offset = pass;
			multiplier = size / gap;
			while (multiplier != 0)
			{
				printf("multiplicador : %d\n", (int) multiplier);
				printf("pareja encontrada %d, con %d\n",(int) array[pass + multiplier * gap] ,(int) array[pass + (multiplier - 1) * gap ]);
				multiplier--;
			}
			while (array[pass + gap] < array[offset])
			{
				swap_int(&array[pass + gap], &array[offset]);
				print_array(array, size);
				pass = offset;
				if (pass != 0)
					offset--;
			}
		}
	/*Sorted by normal insert sort*/
	for (pass = 0; pass < size; pass++)
	{
		if (pass != 0)
			offset = pass - 1;
		while (array[pass] < array[offset])
		{
			swap_int(&array[pass], &array[offset]);
			print_array(array, size);
			pass = offset;
			if (pass != 0)
				offset--;
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

