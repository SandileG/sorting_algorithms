#include "sort.h"

void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Declare all variables at the beginning of the function block */
    size_t i, j;
    int max;
    int *count;

    /* Find the maximum value in the array */
    max = array[0];
    for (i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    /* Create a counting array with size (max + 1) */
    count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    /* Initialize counting array with zeros */
    for (i = 0; i <= max; i++)
        count[i] = 0;

    /* Count occurrences of each element in the array */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Update the original array based on counting array */
    j = 0;
    for (i = 0; i <= max; i++) {
        while (count[i] > 0) {
            array[j++] = i;
            count[i]--;
        }
    }

    /* Free the counting array */
    free(count);
}
