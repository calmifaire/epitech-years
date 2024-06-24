/*
** EPITECH PROJECT, 2022
** lenght
** File description:
** lenght
*/

#include "string.h"

int length(const  string_t *this)
{
    if (!this->str)
        return (-1);
    return (strlen(this->str));
}
