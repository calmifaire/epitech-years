/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** command
*/

#include "../include/server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat_map(char *str, client_t **client)
{
    str = my_strcat2(str, my_itoa((*client)->core->width_map), 1);
    str = my_strcat2(str, " ", 0);
    str = my_strcat2(str, my_itoa((*client)->core->height_map), 1);
    str = my_strcat2(str, " ", 0);
    str = my_strcat2(str, (*client)->core->map, 0);
    str = my_strcat2(str, "\n", 0);
    return (str);
}

void which_command(char *str, client_t **client)
{
    if (strcmp(str, "ID\n") == 0) {
        char *id = strdup("ID ");
        id = my_strcat2(id, my_itoa((*client)->ID), 1);
        id = my_strcat2(id, "\n", 0);
        write((*client)->fd, id, strlen(id));
        free(id);
    }
    if (strcmp(str, "MAP\n") == 0) {
        char *map = fill_str("MAP ");
        map = concat_map(map, client);
        write((*client)->fd, map, strlen(map));
        free(map);
    }
    if (strcmp(str, "READY\n") == 0)
        (*client)->player_is_ready = true;
    if (strcmp(str, "FIRE 1\n") == 0)
        (*client)->fire = 1;
    if (strcmp(str, "FIRE 0\n") == 0)
        (*client)->fire = 0;
}