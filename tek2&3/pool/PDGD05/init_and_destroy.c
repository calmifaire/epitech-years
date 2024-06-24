/*
** EPITECH PROJECT, 2022
** init destroy
** File description:
** init and destroy
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
    this->string_init = &string_init;
    this->string_destroy = &string_destroy;
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &find_at_position;
    this->clear = &clear;
    this->length = &length;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = &find_s;
    this->find_c = &find_c;
}

void string_destroy(string_t *this)
{
    free(this->str);
}
