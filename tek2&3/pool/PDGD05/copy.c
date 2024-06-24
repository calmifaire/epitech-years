/*
** EPITECH PROJECT, 2022
** copy
** File description:
** copy
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t i = 0;
    size_t j;

    if (pos > strlen(this->str))
        return (0);
    for (j = 0; j != pos; j++);
    for (; i != n && this->str[j] != '\0'; i++, j++)
        s[i] = this->str[j];
    if (this->str[j] == '\0' && i != n)
		i++;
    return (i);
}
