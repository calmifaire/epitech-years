/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** client_handling
*/

#include "../include/server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_client(client_t **client)
{
    char buff[256];
    size_t count = 50;
    int size = 0;

    size = read((*client)->fd, buff, count);
    buff[size] = 0;
    which_command(buff, client);
}

void add_client_to_list(client_t **new_client, int socket, int id, core_t *core)
{
    client_t *element = malloc(sizeof(client_t));
    client_t *last = *new_client;
    element->fd = socket;
    element->ID = id;
    element->player_pos_x = 0;
    element->player_pos_y = 0;
    element->score = 0;
    element->game_start = false;
    element->player_is_ready = false;
    element->fire = 0;
    element->core = core;
    element->next = NULL;
    if (*new_client == NULL) {
        element->prev = NULL;
        *new_client = element;
        return;
    } while (last->next != NULL)
        last = last->next;
    last->next = element;
    element->prev = last;
}

void accept_client(core_t *core, int id)
{
    int socket = 0;
    struct sockaddr_in in;
    socklen_t size = sizeof(in);
    if (list_size(core->clients) == 2) {
        fprintf(stderr, "cannot accept more than 2 clients\n");
        return;
    }
    socket = accept(core->server->server_fd, (struct sockaddr *)&in, &size);
    if (socket == -1)
        return;
    write(socket, "New connection\n", 16);
    add_client_to_list(&core->clients, socket, id, core);
    FD_SET(socket, &core->server->read_group);
    FD_SET(socket, &core->server->write_group);
    FD_SET(socket, &core->server->except_group);
}

void update(client_t **list)
{
    client_t *temp = *list;

    while (temp) {
        if ((int)temp->player_pos_y >= temp->core->height_map - 1)
            temp->player_pos_y -= 0.2f * temp->core->gravity;
        if (temp->fire == 1)
            temp->player_pos_y += 0.2f * temp->core->gravity;
        if (temp->fire == 0 && temp->player_pos_y > 0)
            temp->player_pos_y -= 0.2f * temp->core->gravity;
        temp->player_pos_x += 0.2f;
        temp = temp->next;
    }
}

void start_game(client_t **list)
{
    write((*list)->fd, "START\n", 6);
    (*list)->game_start = true;
}