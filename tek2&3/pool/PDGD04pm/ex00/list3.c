/*
** EPITECH PROJECT, 2022
** list
** File description:
** part3
*/

bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    int_list_t last;

    if (*front_ptr == NULL)
        return (false);
    if ((*front_ptr)->next == NULL) {
        *front_ptr = NULL;
        return (false);
    }
    last = *front_ptr;
    while (last->next->next != NULL)
        last = last->next;
    last->next = NULL;
    return (true);
}

bool int_list_del_elem_at_position(int_list_t *front_ptr, unsigned int position)
{
    intt_list_t elem;
    int_list_t prev;
    unsigned int i = 0;

    if (position == 0)
        return(int_list_del_elem_at_front(front_ptr));
    else if (position + 1 == int_list_get_size(*front_ptr))
        return (int_list_del_elem_at_back(front_ptr));
    if (*front_ptr == NULL)
        return (false);
    elem = *front_ptr;
    prev = elem;
    for (;elem->next != NULL && i != position; i++) {
        prev = elem;
        elem = elem->next;
    }
    if (i != position || elem->next == NULL)
        return (false);
    prev->next = elem->next;
    free(elem);
    return (true);
}

void int_list_clear(int_list_t* front_ptr)
{
    *front_ptr = NULL;
}
