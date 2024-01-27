#include "sort.h"

/**
 * exchange_values - Swap two integers in an array.
 * @x: The first integer to exchange.
 * @y: The second integer to exchange.
 */
void exchange_values(int *x, int *y)
{
    int temporary;

    temporary = *x;
    *x = *y;
    *y = temporary;
}

/**
 * knuth_shell_sort - Sort an array of integers in ascending
 *                   order using the shell sort algorithm.
 * @arr: An array of integers.
 * @len: The length of the array.
 *
 * Description: Utilizes the Knuth interval sequence.
 */
void knuth_shell_sort(int *arr, size_t len)
{
    size_t interval, i, j;

    if (arr == NULL || len < 2)
        return;

    for (interval = 1; interval < (len / 3);)
        interval = interval * 3 + 1;

    for (; interval >= 1; interval /= 3)
    {
        for (i = interval; i < len; i++)
        {
            j = i;
            while (j >= interval && arr[j - interval] > arr[j])
            {
                exchange_values(arr + j, arr + (j - interval));
                j -= interval;
            }
        }
        print_array(arr, len);
    }
}
