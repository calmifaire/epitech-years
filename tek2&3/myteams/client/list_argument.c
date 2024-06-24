/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-nykyta.kudrya
** File description:
** list_argument
*/

#include "myteams_client.h"

int get_four_list(int i, receive_t *server, char *buffer)
{
    i = get_three_list(i, server, buffer);
    for (int j = 0; buffer[i] != '\n'; i++){
        server->arg4[j] = buffer[i];
        j++;
        server->arg4[j] = '\0';
    }
    i++;
    return (i);
}

int list_of_five_argument(int i, receive_t *server, char *buffer)
{
    i = get_four_list(i, server, buffer);
    for (int j = 0; buffer[i] != '\n' && (buffer[i + 1] != '\n'
    || buffer[i + 1] != '\0') && buffer[i] != '\0'; i++){
        server->arg5[j] = buffer[i];
        j++;
        server->arg5[j] = '\0';
    }
    if ((buffer[i] == '\n' && buffer[i + 1] == '\0') || buffer[i] == '\0')
        return (0);
    return (i);
}

int get_three_list(int i, receive_t *server, char *buffer)
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
    for (int j = 0; buffer[i] != '\n'; i++){
        server->arg3[j] = buffer[i];
        j++;
        server->arg3[j] = '\0';
    }
    i++;
    return (i);
}

int list_of_four_argument(int i, receive_t *server, char *buffer)
{
    i = get_three_list(i, server, buffer);
    for (int j = 0; buffer[i] != '\n' && (buffer[i + 1] != '\n'
    || buffer[i + 1] != '\0') && buffer[i] != '\0'; i++){
        server->arg4[j] = buffer[i];
        j++;
        server->arg4[j] = '\0';
    }
    if ((buffer[i] == '\n' && buffer[i + 1] == '\0') || buffer[i] == '\0')
        return (0);
    return (i);
}

int list_of_three_argument(int i, receive_t *server, char *buffer)
{
    i = get_two_list(i, server, buffer);
    for (int j = 0; buffer[i] != '\n' && (buffer[i + 1] != '\n'
    || buffer[i + 1] != '\0') && buffer[i] != '\0'; i++) {
        server->arg3[j] = buffer[i];
        j++;
        server->arg3[j] = '\0';
    }
    if ((buffer[i] == '\n' && buffer[i + 1] == '\0') || buffer[i] == '\0')
        return (0);
    return (i);
}
