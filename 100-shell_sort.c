#include "sort.h"

void interchange(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

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
