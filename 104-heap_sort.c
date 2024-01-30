#include "sort.h"

/**
 * swap_elements - Swap two elements in an array.
 * @a: The first element to swap.
 * @b: The second element to swap.
 */
void swap_elements(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Maintain the heap property for a binary tree.
 * @arr: An array representing a binary tree.
 * @size: The size of the array.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void heapify(int *arr, size_t size, size_t base, size_t root)
{
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;
	size_t largest = root;

	if (left < base && arr[left] > arr[largest])
		largest = left;
	if (right < base && arr[right] > arr[largest])
		largest = right;

	if (largest != root)
	{
		swap_elements(arr + root, arr + largest);
		print_array(arr, size);
		heapify(arr, size, base, largest);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order
 *             using the heap sort algorithm.
 * @arr: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *arr, size_t size)
{
	int i;

	if (arr == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(arr, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_elements(arr, arr + i);
		print_array(arr, size);
		heapify(arr, size, i, 0);
	}
}
