/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** server
*/

#include "../include/server.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void dump_bool(client_t **client)
{
    client_t *temp = *client;

    while (temp) {
        if (temp->player_is_ready == true)
            printf("player id : <%d> ready\n", temp->ID);
        temp = temp->next;
    }
}

void update_fd_sets(core_t *core)
{
    client_t *temp = core->clients;

    FD_ZERO(&core->server->read_group);
    FD_SET(core->server->server_fd, &core->server->read_group);

    while (temp) {
        FD_SET(temp->fd, &core->server->read_group);
        temp = temp->next;
    }
    FD_ZERO(&core->server->write_group);
    temp = core->clients;
    while (temp) {
        FD_SET(temp->fd, &core->server->write_group);
        temp = temp->next;
    }
}

void check_read_from_client(core_t *core, client_t *temp)
{
    temp = core->clients;
    while (temp) {
        if (FD_ISSET(temp->fd, &core->server->read_group))
            read_client(&temp);
        temp = temp->next;
    }
}

bool check_float(float nbr)
{
    float res = nbr - ((float)((int)(nbr)));

    if (res == 0)
        return (false);
    else
        return (true);
}

void check_case_p2(int y, int x, core_t *core, client_t *temp)
{
    if (!(y >= 0 && y < core->height_map && x >= 0 &&
    x <= core->width_map)) return;
    if (core->map_array[y][x] == 'c') {
        core->map_array[y][x] = '_';
        send_coin_player2(temp, x, y);
    }
}