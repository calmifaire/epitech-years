/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** init
*/

#include "../include/server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

core_t *init_core(char *values)
{
    core_t *init = malloc(sizeof(core_t));
    char *gravity = get_gravity_from_flag(values);
    char *port = get_port_from_flag(values);
    init->port = atoi(port);
    init->gravity = atoi(gravity);
    init->map = get_map_from_flags(values);
    init->is_game_started = false;
    init->clients = init_clients();
    init->server = init_server(init);
    init->height_map = 0;
    init->width_map = 0;
    free(port);
    free(gravity);

    return (init);
}

void init_socket(server_t *server)
{
    int opt = 1;
    server->server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->server_fd < 0)
        exit(84);
    server->in.sin_addr.s_addr = htonl(INADDR_ANY);
    server->in.sin_family = AF_INET;
    server->in.sin_port = htons(server->core->port);

    setsockopt(server->server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if (bind(server->server_fd, (struct sockaddr *)&server->in,
    sizeof(server->in)) < 0) {
        fprintf(stderr, "Failed to bind\n");
        exit(84);
    }
    if (listen(server->server_fd, 100) < 0) {
        fprintf(stderr, "Failed to listen\n");
        exit(84);
    }
}

client_t *init_clients(void)
{
    client_t *init = NULL;

    return (init);
}

server_t *init_server(core_t *core)
{
    server_t *init = malloc(sizeof(server_t));

    init->core = core;
    init->server_fd = 0;

    return (init);
}