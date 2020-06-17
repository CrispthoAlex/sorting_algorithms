#include "sort.h"

size_t findIndex(int *array, size_t size, int target);
char *_memset(char *s, char b, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
/**
 * counting_sort - sorts an array of integers with counting sorting
 *
 * @array: array
 * @size: size of the array
 * Return: Void
 */
void counting_sort(int *array, size_t size)
{
	int i = 0, max = 0, min = 0, j = 0, counter = 0;
	int *index_array, *count_array, *sum_array, *output_array;
	size_t my_index;

	if (size < 2 || !array)
		return;
	min = array[0];
	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] < min)
			min = array[i];
		if (array[i] > max)
			max = array[i];
	}
	index_array = _calloc(max + 1, sizeof(int));
	if (index_array == NULL)
		return;
	for (i = 0; i <= max; i++)
		index_array[i] = i;
	/*print_array(index_array, max + 1);*/
	count_array = _calloc(max + 1, sizeof(int));
	if (index_array == NULL)
		return;
	/*input_counter*/
	for (i = 0; i < (int)size; i++)
	{
		counter = 0;
		for (j = 0; j < (int)size; j++)
		{
			if (array[i] == array[j])
			{
				counter++;
			}
		}
	my_index = findIndex(index_array, max + 1, array[i]);
	count_array[my_index] = counter;
	}
	/*print_array(count_array, max + 1);*/
	sum_array = _calloc(max + 1, sizeof(int));
	if (index_array == NULL)
		return;
	sum_array[0] = count_array[0];
	for (i = 1; i < max + 1; i++)
	{
		sum_array[i] = sum_array[i - 1] + count_array[i];
	}
	print_array(sum_array, max + 1);
	output_array = _calloc(size, sizeof(int));
	if (index_array == NULL)
		return;
	for (i = 0; i < (int)size; i++)
	{
		my_index = findIndex(index_array, max + 1, array[i]);
		output_array[sum_array[my_index] - 1] = array[i];
		sum_array[my_index]--;
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = output_array[i];
	}
	free(output_array);
	free(sum_array);
	free(count_array);
	free(index_array);
}

/**
 *_calloc - using calloc with malloc
 *@nmemb: number of entries
 *@size: bytes of the entry
 *Return: 0
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *pointer;

	if (size <= 0 || nmemb <= 0)
		return (NULL);
	pointer = malloc(nmemb * size);
	if (pointer == NULL)
		return (NULL);
	pointer = _memset(pointer, 0, nmemb * size);
	return ((void *)pointer);
}

/**
 *_memset -  sets memory values from *s to n quantity
 *@s: initial address
 *@b: value
 *@n: quantity of bytes
 *Return: pointer to the memory area of s
 */
char *_memset(char *s, char b, unsigned int n)
{
	char **pointer_to_s;
	unsigned int i;

	pointer_to_s = &s;
	for (i = 0; i < n; i++)
	{
	*(*pointer_to_s + i) = b;
	}
	return (*pointer_to_s);
}

/**
 *findIndex -  finds the nearest index of target
 *@array: array to be search
 *@size: size of array
 *@target: value of target
 *Return: Value of index in which target is
 */
size_t findIndex(int *array, size_t size, int target)
{
	size_t i = 0;

	while ((i < size) && (array[i] != target))
		i++;

	return (i);
}
