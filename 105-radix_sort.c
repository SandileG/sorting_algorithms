#include "sort.h"

/**
 * find_maximum - Find the maximum value in an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum value in the array.
 */
int find_maximum(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		max = array[i];
	}

	return (max);
}

/**
 * counting_sort_radix - Perform counting sort on the significant digits of
 *                       an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 * @base: The base (10 for decimal).
 * @exp: The current exponent representing the significant digit.
 * @buff: A buffer for intermediate storage.
 */
void counting_sort_radix(int *array, ssize_t size, int base,
			int exp, int *buff)
{
	ssize_t i;
	int *count = malloc(sizeof(int) * base);

	if (count == NULL)
		return;

	for (i = 0; i < base; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % base]++;

	for (i = 1; i < base; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		buff[count[(array[i] / exp) % base] - 1] = array[i];
		count[(array[i] / exp) % base]--;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];

	free(count);
}

/**
 * radix_sort_algorithm - Perform radix sort on an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int *buffer;
	int max_val;
	ssize_t exp;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	max_val = find_maximum(array, size);

	for (exp = 1; max_val / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, 10, exp, buffer);
		print_array(array, size);
	}

	free(buffer);
}
