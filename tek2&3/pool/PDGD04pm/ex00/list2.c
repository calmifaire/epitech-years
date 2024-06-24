/*
** EPITECH PROJECT, 2022
** list
** File description:
** part2
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "int_list.h"

bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem, unsigned int position)
{
    int_list_t new;
    int_list_t add;
    unsigned int i;

    i = 0;
    if (position == 0)
        return (int_list_add_elem_at_front(front_ptr, elem));
    if (*front_ptr == NULL)
        return (false);
    new = malloc(sizeof(int_list_t));
    if (new == NULL)
        return (false);
    new->value = elem;
    add = *front_ptr;
    while (add->next != NULL && i != position)
    {
        add = add->next;
        i++;
    }
    add->next = new;
    return (true);
}

int int_list_get_elem_at_front(int_list_t list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}

int int_list_get_elem_at_back(int_list_t list)
{
    if (list == NULL)
        return (0);
    while (list->next != NULL)
        list = list->next;
    return (list->value);
}

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    unsigned int i = 0;

    if (list == NULL)
        return (0);
    if (position == 0)
        return(int_list_get_elem_at_front(list));
    while (list->next != NULL && i < position)
    {
        list = list->next;
        i++;
    }
    if (i != position || list == NULL)
        return (0);
    return (list->value);
}

bool int_list_del_elem_at_front(int_list_t *front_ptr)
{
    if (*front_ptr == NULL)
        return (false);
    *front_ptr = (*front_ptr)->next;
    if (*front_ptr == NULL)
        return (false);
    return (true);
}
