/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** serverJP2T3
*/

#include "../include/server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_list(client_t *client)
{
    client_t *temp = client;

    while (client) {
        temp = client;
        client = client->next;
        free(temp);
    }
}

void free_server(core_t *core)
{
    free(core->server->core);
    free(core->server);
}

void free_core(core_t *core)
{
    free_list(core->clients);
    free_server(core);
    free(core->map);
    free(core->map_array);
    free(core);
}

int main(int ac, char **av)
{
    if (ac == 7) {
        char *flags = check_flags(av);
        core_t *core = init_core(flags);
        if (check_map(core) == 84) {
            return (84);
        }
        core->map = format_map(core->map);
        free(flags);
        if (!core)
            return (84);
        start_serveur(core);
        free_core(core);
        return (0);
    }
    return (84);
}