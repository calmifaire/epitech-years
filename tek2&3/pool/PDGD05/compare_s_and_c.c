/*
** EPITECH PROJECT, 2022
** compare
** File description:
** s c
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    int i;

    if (!this->str)
        return (-1);
    i = strcmp(this->str, str->str);
    return (i);
}

int compare_c(const string_t *this, const char *str)
{
    int i;

    if (!this->str)
        return (-1);
    i = strcmp(this->str, str);
    return (i);
}
