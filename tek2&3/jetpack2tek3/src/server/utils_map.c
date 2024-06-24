/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** utils_map
*/

#include "../include/server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calc_width_map(char *map)
{
    int i = 0;
    for (; map[i] != '\n'; ++i);
    return (i);
}

int calc_height_map(char *map)
{
    int counter = 0;
    for (int i = 0; map[i]; ++i) {
        if (map[i] == '\n')
            ++counter;
    }
    return (++counter);
}

int check_line(char c, char *str, int *counter)
{
    if (c == '\n') {
        if (*counter - 1 != calc_width_map(str))
            return (1);
        *counter = 0;
    }
    return (0);
}

int check_if_map_is_valid(char *map)
{
    int counter = 0;

    for (int i = 0; map[i]; ++i) {
        ++counter;
        if (check_line(map[i], map, (&counter)) == 1) {
            return (1);
        }
    }
    return (0);
}