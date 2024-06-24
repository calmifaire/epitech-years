/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** utils
*/

#include "../include/server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat2(char *str1, char *str2, int freeable)
{
    int	i = 0;
    int	j = 0;
    int size = (strlen(str1) + strlen(str2));
    char *res = malloc(sizeof(char) * size + 1);

    while (str1[i]) {
        res[i] = str1[i];
        ++i;
    }
    while (str2[j]) {
        res[i] = str2[j];
        i++;
        j++;
    }
    res[i] = 0;
    free(str1);
    if (freeable == 1)
        free(str2);
    return (res);
}

char *my_revstr(char *str)
{
    char temp = 0;
    int len = strlen(str) - 1;

    for (int i = 0; i < len; ++i) {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        --len;
    }
    return (str);
}

int my_int_len(int nb)
{
    int counter = 0;

    if (nb == 0)
        return (1);
    if (nb < 0)
        return (84);

    while (nb > 0) {
        ++counter;
        nb /= 10;
    }
    return (counter);
}

char *my_itoa(int nbr)
{
    int sign = 0;
    int i = 0;

    if (nbr < 0) {
        sign = 1;
        nbr *= -1;
    }
    int len = my_int_len(nbr);
    char *res = malloc(sizeof(char) * (len + 1));
    res[len] = 0;

    for (; i != len; ++i) {
        res[i] = nbr % 10 + 48;
        nbr /= 10;
    }
    if (sign == 1)
        res[i] = '-';
    my_revstr(res);
    return (res);
}
