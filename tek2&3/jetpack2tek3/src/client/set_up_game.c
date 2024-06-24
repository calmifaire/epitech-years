/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** set_up_game
*/

#include "../include/client.h"

static void parse_map(client_t *client)
{
    int i = 0;
    int j = 0;

    client->width = atoi(client->receive);
    i = get_height(client);
    client->cells = malloc(sizeof(char)*(client->height * client->width));
    if (!client->cells)
        free_all(client, 84);
    for (;client->receive[i] != ' ' && client->receive[i] != '\0'; i++);
    for (;client->receive[i] == ' ' && client->receive[i] != '\0'; i++);
    for (j = 0; client->receive[i] != '\n'
    && client->receive[i] != '\0'; i++) {
        client->cells[j] = client->receive[i];
        j++;
    }
    init_map(client);
}

static void check_message(client_t *client)
{
    if (strncmp(client->receive, "ID ", 3) == 0) {
        client->receive = next_word(client->receive);
        client->player1->id = atoi(client->receive);
    }
    else if (strncmp(client->receive, "MAP ", 4) == 0) {
        client->receive = next_word(client->receive);
        parse_map(client);
    }
    if (strncmp(client->receive, "START\n", 6) == 0) {
        client->start = true;
    }
}

static int check_fd(client_t *client, fd_set *rfds)
{
    int i;

    if (FD_ISSET(client->fd, rfds) == 1) {
        i = read(client->fd, client->receive, 6000);
        if (i < 0)
            return (-1);
        client->receive[i] = '\0';
        if (strcmp(client->receive, "") == 0) {
            return (-1);
        }
        if (client->start == false)
            check_message(client);
    }
    return (0);
}

int check_ret(client_t *client, fd_set *rfds, int ret)
{
    if (ret == -1)
        perror("select()");
    if (ret) {
        if (check_fd(client, rfds) == -1)
            return (-1);
    }
    return (0);
}

void loading(client_t *client)
{
    if (client->player1->id == 0)
        write(client->fd, "ID\n\0", 4);
    else if (client->map == NULL)
        write(client->fd, "MAP\n\0", 5);
    else {
        write(client->fd, "READY\n\0", 7);
        client->ready = true;
    }
}