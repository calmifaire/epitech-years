/*
** EPITECH PROJECT, 2022
** assign
** File description:
** s c
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    this->string_destroy(this);
    this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    this->string_destroy(this);
    this->str = strdup(s);
}
