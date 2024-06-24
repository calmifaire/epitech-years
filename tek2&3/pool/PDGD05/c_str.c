/*
** EPITECH PROJECT, 2022
** c_str
** File description:
** str
*/

#include <stdio.h>
#include "string.h"

const char *c_str(const string_t *this)
{
    const char * r = strdup(this->str);

    return (r);
}
