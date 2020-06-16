#include "sort.h"
void quick_sort_rec(int *array, size_t size, int low, int high);

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array unsorted to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_rec(array, size, 0, size - 1);
}

/**
 * quick_sort_rec - sorts an array of integers in ascending order
 * @array: array unsorted to be sorted
 * @size: size of array
 * @low: start part of the array
 * @high: end part of the array
 */
void quick_sort_rec(int *array, size_t size, int low, int high)
{
	int pivote;

	if (low >= high)
		return;
	pivote = partition(array, size, low, high);
	quick_sort_rec(array, size, low, pivote - 1); /* Left */
	quick_sort_rec(array, size, pivote + 1, high); /* Right */
}

/**
 * partition - sorts an array of integers in ascending order
 * @array: array unsorted to be sorted
 * @size: size of array
 * @low: start part of the array
 * @high: end part of the array
 * Return: index of the pivot at the end
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot, actual, min;

	pivot = high;
	min = low;
	for (actual = low; actual <= high; actual++)
	{
		if (array[actual] < array[pivot])
		{
			if (actual != min)
			{
				swap_int(&array[actual], &array[min]);
				print_array(array, size);
			}
			min++;
		}
	}
	if (pivot != min)
	{
		swap_int(&array[pivot], &array[min]);
		print_array(array, size);
	}
	return (pivot);
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
