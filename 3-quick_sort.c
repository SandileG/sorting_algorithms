#include "sort.h"

/**
 * swap_elements - Swap two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap_elements(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partition the array using the Lomuto scheme.
 * @array: The array to be partitioned.
 * @size: The size of the array.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 *
 * Return: The final partition index.
 */
size_t lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_elements(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	swap_elements(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
 * lomuto_quick_sort - Implement Quick sort using Lomuto partition.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @low: The starting index of the array partition.
 * @high: The ending index of the array partition.
 */
void lomuto_quick_sort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, size, low, high);

		lomuto_quick_sort(array, size, low, pivot - 1);
		lomuto_quick_sort(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort - Sort an array of integers using Quick sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quick_sort(array, size, 0, size - 1);
}
