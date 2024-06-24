/*
** EPITECH PROJECT, 2022
** concat
** File description:
** concat
*/

#include <string.h>
#include "concat.h"

void  concat_strings (const  char *str1 , const  char *str2 , char **res)
{
    *res = malloc(sizeof(char*)*(strlen(str1)+strlen(str2)));
    if (res) {
        strcpy(*res,str1);
        strcat(*res,str2);
    }
}

void  concat_struct (concat_t *str)
{
    str->res = malloc(sizeof(char*)*(strlen(str->str1)+strlen(str->str2)));
    if (str->res) {
        strcpy(str->res,str->str1);
        strcat(str->res,str->str2);
    }
}
