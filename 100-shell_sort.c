#include "sort.h"

/**
 * interchange - Swap the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void interchange(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Sort an array of integers in ascending order
 *		using the Shell sort algorithm with Knuth sequence.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	while (interval < size / 3)
		interval = interval * 3 + 1;

	for (; interval >= 1; interval /= 3)
	{
		for (i = interval; i < size; i++)
		{
			j = i;
			while (j >= interval && array[j - interval] > array[j])
			{
				interchange(array + j, array + (j - interval));
				j -= interval;
			}
		}
		print_array(array, size);
	}
}
