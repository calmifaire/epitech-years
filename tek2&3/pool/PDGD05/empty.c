/*
** EPITECH PROJECT, 2022
** empty
** File description:
** empty
*/

#include <string.h>
#include "string.h"

int empty(const string_t *this)
{
    if (strlen(this->str) == 0)
        return (1);
    return (0);
}
