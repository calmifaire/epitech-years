/*
** EPITECH PROJECT, 2022
** loop
** File description:
** loop of the client
*/

#include "myteams_client.h"

void put_to_zero(server_t *client, receive_t *server)
{
    client->message[0] = '\0';
    client->arg[0] = '\0';
    server->code[0] = '\0';
    server->arg1[0] = '\0';
    server->arg2[0] = '\0';
    server->arg3[0] = '\0';
    server->arg4[0] = '\0';
    server->arg5[0] = '\0';
}

int check_fd(server_t *client, fd_set *rfds, receive_t *server)
{
    char buffer[2000];
    int i;

    buffer[0] = '\0';
    if (FD_ISSET(0, rfds) == 1) {
        for (i = 0; read(0, buffer + i, 1) > 0 && buffer[i] != '\n'; i++);
        buffer[i + 1] = '\0';
        check_command_of_no_argument(buffer, client);
    }
    if (FD_ISSET(client->fd, rfds) == 1) {
        i = read(client->fd, buffer, 2000);
        if (i < 0)
            return (-1);
        buffer[i] = '\0';
        if (strcmp(buffer,"") == 0)
            return (-1);
        get_code(buffer, server);
    }
    return (0);
}

int check_ret(server_t *client, fd_set *rfds, receive_t *server, int ret)
{
    if (ret == -1)
            perror("select()");
        if (ret) {
            if (check_fd(client, rfds, server) == -1)
                return (-1);
        }
    return (0);
}

void loop_client(server_t *client, receive_t *server)
{
    fd_set rfds;
    int ret;

    while (1){
        put_to_zero(client, server);
        FD_ZERO(&rfds);
        FD_SET(0, &rfds);
        FD_SET(client->fd, &rfds);
        ret = select(client->fd + 1, &rfds, NULL, NULL, NULL);
        if (check_ret(client, &rfds, server, ret) == -1)
            return;
    }
}
