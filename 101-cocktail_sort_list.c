#include "sort.h"

/**
 * swap_nodes_forward - Swap a node with the next node in a doubly-linked list.
 * @list: A pointer to the head of the doubly-linked list.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @current: A pointer to the node to be swapped.
 */
void swap_nodes_forward(listint_t **list, listint_t **tail, listint_t **current)
{
    listint_t *tmp = (*current)->next;

    if ((*current)->prev != NULL)
        (*current)->prev->next = tmp;
    else
        *list = tmp;

    tmp->prev = (*current)->prev;
    (*current)->next = tmp->next;

    if (tmp->next != NULL)
        tmp->next->prev = *current;
    else
        *tail = *current;

    (*current)->prev = tmp;
    tmp->next = *current;
    *current = tmp;
}

/**
 * swap_nodes_backward - Swap a node with the previous node in a doubly-linked list.
 * @list: A pointer to the head of the doubly-linked list.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @current: A pointer to the node to be swapped.
 */
void swap_nodes_backward(listint_t **list, listint_t **tail, listint_t **current)
{
    listint_t *tmp = (*current)->prev;

    if ((*current)->next != NULL)
        (*current)->next->prev = tmp;
    else
        *tail = tmp;

    tmp->next = (*current)->next;
    (*current)->prev = tmp->prev;

    if (tmp->prev != NULL)
        tmp->prev->next = *current;
    else
        *list = *current;

    (*current)->next = tmp;
    tmp->prev = *current;
    *current = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *tail, *current;
    int not_sorted = 0;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (tail = *list; tail->next != NULL;)
        tail = tail->next;

    while (not_sorted == 0)
    {
        not_sorted = 1;

        for (current = *list; current != tail; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes_forward(list, &tail, &current);
                print_list((const listint_t *)*list);
                not_sorted = 0;
            }
        }

        for (current = current->prev; current != *list; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes_backward(list, &tail, &current);
                print_list((const listint_t *)*list);
                not_sorted = 0;
            }
        }
    }
}
