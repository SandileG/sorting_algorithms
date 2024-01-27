#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>

/* Provided structures */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Provided functions */
void print_array(const int *array, size_t size);
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap(int *a, int *b);
size_t lomuto_partition(int *array, size_t size, int low, int high);
void lomuto_quick_sort(int *array, size_t size, int low, int high);
void quicksort(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_nodes_forward(listint_t **list, listint_t **tail,
			listint_t **current);
void swap_nodes_backward(listint_t **list, listint_t **tail,
			listint_t **current);
void counting_sort(int *array, size_t size);

#endif /* SORT_H */
