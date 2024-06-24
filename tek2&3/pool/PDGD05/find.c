/*
** EPITECH PROJECT, 2022
** find
** File description:
** find
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    int i = 0;

    if (strlen(this->str) < pos)
        return (-1);
    if (strlen(this->str) - pos < strlen(str->str))
        return (-1);
    for (;strncmp(this->str + pos, str->str, strlen(str->str)) != 0
             && this->str[pos] != '\0'; pos++);
    if (strncmp(this->str + pos, str->str, strlen(str->str)) != 0)
        return (-1);
    return (pos);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    if (strlen(this->str) < pos)
        return (-1);
    if (strlen(this->str) - pos < strlen(str))
        return (-1);
    for (;strncmp(this->str + pos, str, strlen(str)) != 0 
    && this->str[pos] != '\0'; pos++);
    if (strncmp(this->str + pos, str, strlen(str)) != 0)
        return (-1);
    return (pos);
}
