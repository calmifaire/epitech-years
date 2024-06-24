/*
** EPITECH PROJECT, 2022
** clears
** File description:
** clears
*/

#include "string.h"

void clear(string_t *this)
{
    if (!this->str)
        return;
    for (int i = 0; this->str[i] != '\0'; i++)
        this->str[i] = '\0';
}
