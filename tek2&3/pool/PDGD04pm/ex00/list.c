/*
** EPITECH PROJECT, 2022
** list
** File description:
** part1
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

unsigned int int_list_get_size (int_list_t list)
{
    unsigned i;
    for (i = 0; list != NULL; i++);
    return i;
}

bool int_list_is_empty(int_list_t list)
{
    if (list == NULL)
        return (true);
    return (false);
}

void int_list_dump(int_list_t list)
{
    while (list != NULL)
    {
        printf("%d\n", list->value);
        list = list->next;
    }
}

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_list_t n;

    if ((n = malloc(sizeof(int_list_t))) == NULL)
        return (false);
    n->value = elem;
    n->next = *front_ptr;
    *front_ptr = n;
    return (true);
}

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_list_t last;
    int_list_t new;

    if ((last = malloc(sizeof(int_list_t))) == NULL)
        return (false);
    last->next = NULL;
    last->value = elem;
    if (*front_ptr == NULL)
        return (int_list_add_elem_at_front(front_ptr, elem));
    new = *front_ptr;
    while (new->next != NULL)
        new = new->next;
    new->next = last;
    return (true);
}

