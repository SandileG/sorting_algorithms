#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: This function implements the Bubble sort algorithm to
 *              arrange the elements of the given array in ascending order.
 *              It iteratively compares adjacent elements and swaps them if
 *              they are in the wrong order. The process is repeated until
 *              no more swaps are needed, indicating that the array is sorted.
 *              The function also prints the array after each swap.
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i;

	if (size < 2)
	{
		return;  /* No need to sort if size is less than 2 */
	}

	do {
		swapped = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				/* Swap elements */
				int temp = array[i];

				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;

				/* Print the array after each swap */
				print_array(array, size);
			}
		}
		size--;  /* Exclude the last element in subsequent passes */
	} while (swapped);
}
