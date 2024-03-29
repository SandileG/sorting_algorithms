#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/* Provided structures */
/**
 * struct listint_s - Doubly linked list node structure
 * @n: Integer data stored in the node
 * @prev: Pointer to the previous node in the list
 * @next: Pointer to the next node in the list
 *
 * Description: This structure represents a node in a doubly linked list.
 * It contains an integer data element, and pointers to the previous and
 * next nodes in the list.
 */
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
int maximus(int *array, int size);
void swap_elements(int *a, int *b);
void heapify(int *arr, size_t size, size_t base, size_t root);
int find_maximum(int *array, size_t size);
void counting_sort_radix(int *array, ssize_t size, int base,
			int exp, int *buff);

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
void merge_sort(int *array, size_t size);
void heap_sort(int *arr, size_t size);
void radix_sort(int *array, size_t size);


#endif /* SORT_H */
