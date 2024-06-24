/*
** EPITECH PROJECT, 2022
** append
** File description:
** s c
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    size_t j = (strlen(this->str) + strlen(ap->str) + 1);

    this->str = (char *)realloc(this->str,sizeof(char) * j);
    strcat(this->str, ap->str);
}

void append_c(string_t *this, const char *ap)
{
    size_t j = (strlen(this->str) + strlen(ap) + 1);

    this->str = (char *)realloc(this->str,sizeof(char) * j);
    strcat(this->str, ap);
}
