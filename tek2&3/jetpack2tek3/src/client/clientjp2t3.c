/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** clientJP2T3
*/

#include "../include/client.h"

void *set_up(client_t *client)
{
    fd_set rfds;
    int ret = 0;

    while (client->finish == false){
        client->receive[0] = '\0';
        FD_ZERO(&rfds);
        FD_SET(client->fd, &rfds);
        ret = select(client->fd + 1, &rfds, NULL, NULL, NULL);
        if (check_ret(client, &rfds, ret) == -1)
            free_all(client, 84);
        if (client->ready != true)
            loading(client);
        if (client->start == true) {
            sem_post(&client->semaphore_graphic);
            check_game(client);
        }
    }
    pthread_exit(NULL);
}

static bool create_socket(client_t *client)
{
    int enable = 1;

    client->fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (client->fd == -1)
        return (true);
    if (setsockopt(client->fd, SOL_SOCKET, SO_REUSEADDR, &enable,
    sizeof(int)) == -1)
        return (true);
    if ((connect(client->fd, (struct sockaddr *)&client->server,
    sizeof(client->server))) < 0)
        return (true);
    return (false);
}

static bool get_params(client_t *client)
{
    int port;
    char *check_err = NULL;

    port = (int)strtol(client->port, &check_err, 10);
    if (strcmp(client->ip, "localhost") == 0)
        client->ip = "127.0.0.1";
    if ((check_err && *check_err != '\0') || port <= 0)
        return (true);
    client->server.sin_port = htons(port);
    client->server.sin_family = AF_INET;
    if (inet_pton(AF_INET, client->ip, &client->server.sin_addr) <= 0)
        return (true);
    return (false);
}

static bool check_flag(int ac, char **av, client_t *client)
{
    for (int i = 0; i != ac; i++) {
        if (strcmp(av[i], "-p") == 0 && i + 1 <= ac
        && strcmp(av[i + 1], "-h") != 0)
            client->port = av[i + 1];
        if (strcmp(av[i], "-h") == 0 && i + 1 <= ac
        && strcmp(av[i + 1], "-p") != 0)
            client->ip = av[i + 1];
    }
    if (client->port == NULL || client->ip == NULL)
        return (true);
    return (false);
}

int main(int ac, char **av)
{
    client_t client = {0};
    if (ac != 5 || check_flag(ac, av, &client) == true)
        return (84);
    if (get_params(&client) == true || create_socket(&client) == true ||
    init_string_struct(&client) == true)
        return (84);
    init_thread_network_and_graphic(&client);
    join_graphic(&client);
    join_network(&client);
    free_all(&client, 0);
    return (0);
}