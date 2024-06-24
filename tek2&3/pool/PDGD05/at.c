/*
** EPITECH PROJECT, 2022
** at
** File description:
** at position
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

char find_at_position(const string_t *this, size_t pos)
{
    if (pos > strlen(this->str) - 1)
        return (-1);
    return (this->str[pos]);
}
