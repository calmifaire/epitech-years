/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** flags
*/

#include "../include/server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_port_from_flag(char *str)
{
    int i  = 0;
    char *res = malloc(sizeof(char) * strlen(str));
    for (; str[i] != ':'; ++i) {
        res[i] = str[i];
    }
    res[i] = 0;
    return (res);
}

char *get_gravity_from_flag(char *str)
{
    int i = 0;
    int j = 0;
    char *res = malloc(sizeof(char) * strlen(str));
    for (; str[i] != ':'; ++i);
    ++i;
    for (; str[i] != ':'; ++i) {
        res[j] = str[i];
        ++j;
    }
    res[j] = 0;
    return (res);
}

char *get_map_from_flags(char *str)
{
    int i = 0;
    int counter = 0;
    for (; str[i]; ++i) {
        if (str[i] == ':')
            ++counter;
        if (counter == 2)
            break;
    }
    ++i;
    return (&str[i]);
}

char *fill_str(char *str)
{
    char *res = malloc(sizeof(char) * (strlen(str) + 1));
    res[strlen(str)] = '\0';

    for (int i = 0; str[i]; ++i) {
        res[i] = str[i];
    }
    return (res);
}

char *check_flags(char **av)
{
    char *infos = NULL;
    for (int i = 0; av[i]; ++i) {
        if (strcmp(av[i], "-p") == 0) {
            infos = fill_str(av[i + 1]);
        }
    }
    for (int i = 0; av[i]; ++i) {
        if (strcmp(av[i], "-g") == 0) {
            infos = my_strcat2(infos, ":", 0);
            infos = my_strcat2(infos, av[i + 1], 0);
        }
    }
    for (int i = 0; av[i]; ++i) {
        if (strcmp(av[i], "-m") == 0) {
            infos = my_strcat2(infos, ":", 0);
            infos = my_strcat2(infos, open_map(av[i + 1]), 1);
        }
    }
    return (infos);
}