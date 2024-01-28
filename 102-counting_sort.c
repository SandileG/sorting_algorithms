#include "sort.h"

/**
 * counting_sort - Sort an array of integers using Counting sort algorithm.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	size_t max;
	size_t i, index;
	int *count_array;

	if (array == NULL || size < 2)
		return;

	max = (size_t)array[0];

	for (i = 1; i < size; i++)
	{
		if ((size_t)array[i] > max)
			max = (size_t)array[i];
	}

	count_array = malloc((max + 1) * sizeof(int));

	if (count_array == NULL)
		return;

	for (i = 0; i <= max; i++)
		count_array[i] = 0;

	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	print_array(count_array, max + 1);

	index = 0;

	for (i = 0; i <= max; i++)
	{
		int j;
		for (j = 0; j < count_array[i]; j++)
		{
			array[index] = (int)i;
			index++;
		}
	}

	print_array(count_array, max + 1);

	free(count_array);
}
