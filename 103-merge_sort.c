#include "sort.h"

/**
 * merge_subarray - Merge two sorted subarrays into one sorted subarray.
 * @subarray: The original subarray.
 * @buffer: A buffer to store the sorted subarray.
 * @start: The start index of the subarray.
 * @middle: The middle index of the subarray.
 * @end: The end index of the subarray.
 */
static void merge_subarray(int *subarray, int *buffer, size_t start,
			size_t middle, size_t end)
{
	size_t i = start, j = middle, k = 0;

	printf("Merging...\n[Left]: ");
	print_array(subarray + start, middle - start);

	printf("[Right]: ");
	print_array(subarray + middle, end - middle);

	while (i < middle && j < end)
	buffer[k++] = (subarray[i] < subarray[j])
		? subarray[i++] : subarray[j++];

	while (i < middle)
		buffer[k++] = subarray[i++];

	while (j < end)
		buffer[k++] = subarray[j++];

	for (i = start, k = 0; i < end; i++)
		subarray[i] = buffer[k++];

	printf("[Done]: ");
	print_array(subarray + start, end - start);
}

/**
 * merge_sort_recursive - Recursively apply the merge sort algorithm.
 * @subarray: The subarray to be sorted.
 * @buffer: A buffer to store the sorted result.
 * @start: The start index of the subarray.
 * @end: The end index of the subarray.
 */
static void merge_sort_recursive(int *subarray, int *buffer, size_t start,
				size_t end)
{
	size_t middle;

	if (end - start > 1)
	{
		middle = start + (end - start) / 2;
		merge_sort_recursive(subarray, buffer, start, middle);
		merge_sort_recursive(subarray, buffer, middle, end);
		merge_subarray(subarray, buffer, start, middle, end);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending order
 *              using the merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
