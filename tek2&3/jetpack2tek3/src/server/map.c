/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** map
*/

#include "../include/server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_array_map(core_t *core)
{
    char *container = fill_str(core->map);
    core->map_array = malloc(sizeof(char *) * (core->height_map));
    core->map_array[core->height_map - 1] = NULL;
    char *ptr = strtok(container, "\n");

    for (int i = 0; i < core->height_map; ++i) {
        core->map_array[i] = malloc(sizeof(char) * core->width_map + 1);
        core->map_array[i][0] = 0;
        core->map_array[i] = my_strcat2(core->map_array[i], ptr, 0);
        ptr = strtok(NULL, "\n");
    }
    free(ptr);
    free(container);
}

int check_map(core_t *core)
{
    core->width_map = calc_width_map(core->map);
    core->height_map = calc_height_map(core->map) - 1;
    printf("%d\n", core->height_map);
    init_array_map(core);
    if (check_if_map_is_valid(core->map) == 0)
        return (0);
    return (84);
}

char *format_map(char *map)
{
    char *str = malloc(sizeof(char) * strlen(map));
    int j = 0;

    for (int i = 0; map[i]; ++i) {
        if (map[i] == '\n')
            continue;
        str[j] = map[i];
        ++j;
    }
    str[j] = 0;
    return (str);
}

char *open_map(char *filepath)
{
    long int len = 0;
    char *res = NULL;
    int i = 0;
    FILE *file = fopen(filepath, "r");
    if (!file)
        exit(84);
    fseek(file, 0L, SEEK_END);
    len = ftell(file);
    if (len == 0)
        exit(84);
    fseek(file, 0L, SEEK_SET);
    res = malloc(sizeof(char) * len + 1);
    while (1) {
        if (feof(file))
            break;
        res[i] = fgetc(file);
        ++i;
    }
    res[i - 1] = 0;
    return (res);
}