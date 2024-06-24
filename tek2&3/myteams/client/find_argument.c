/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-nykyta.kudrya
** File description:
** find_argument
*/

#include "myteams_client.h"

int get_two_list(int i, receive_t *server, char *buffer)
{
    for (int j = 0; buffer[i] != '\n'; i++){
        server->arg1[j] = buffer[i];
        j++;
        server->arg1[j] = '\0';
    }
    i++;
    for (int j = 0; buffer[i] != '\n'; i++){
        server->arg2[j] = buffer[i];
        j++;
        server->arg2[j] = '\0';
    }
    i++;
    return (i);
}

void two_argument_send_by_server(char *buffer, receive_t *server)
{
    int j;
    int i = 0;
    int nb = 0;

    while (nb != 2) {
        for (; buffer[i] != '\n' && buffer[i] != '\0'; i++);
        i++;
        nb++;
    }
    for (j = 0; buffer[i] != '\n' && buffer[i + 1] != '\0'
    && buffer[i] != '\0'; i++) {
        server->arg2[j] = buffer[i];
        j++;
    }
    server->arg2[j] = '\0';
}

void argument_one_send_by_server(char *buffer, receive_t *server)
{
    int j;
    int i;

    for (i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++);
    i++;
    for (j = 0;buffer[i] != '\n' && buffer[i] != '\0'; i++) {
        server->arg1[j] = buffer[i];
        j++;
    }
    server->arg1[j] = '\0';
}

void one_argument_send_by_server(char *buffer, receive_t *server)
{
    int j;
    int i;

    for (i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++);
    i++;
    for (j = 0;buffer[i] != '\n' && buffer[i + 1] != '\0'
    && buffer[i] != '\0'; i++) {
        server->arg1[j] = buffer[i];
        j++;
    }
    server->arg1[j] = '\0';
}
