#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node.
 * @prev: Pointer to the previous element of the list.
 * @next: Pointer to the next element of the list.
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Provided functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);

/* Sorting algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap(int *a, int *b);
size_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size);
void lomuto_quick_sort(int *array, ssize_t low, ssize_t high, size_t size);
void quicksort(int *array, int low, int high, size_t size);

#endif /* SORT_H */
