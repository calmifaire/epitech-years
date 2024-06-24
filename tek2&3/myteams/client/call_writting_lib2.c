/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-nykyta.kudrya
** File description:
** call_writting_lib2
*/

#include "myteams_client.h"

void listing_reply(char *buffer, receive_t *server)
{
    int i = 3;

    while ((i = list_of_four_argument(i, server, buffer)) != 0) {
        client_thread_print_replies(server->arg1, server->arg2,
        strtol(server->arg3, NULL, 0), server->arg4);
        i = i + 2;
    }
    client_thread_print_replies(server->arg1, server->arg2,
        strtol(server->arg3, NULL, 0), server->arg4);
}

void listing_thread(char *buffer, receive_t *server)
{
    int i = 3;

    while ((i = list_of_five_argument(i, server, buffer)) != 0) {
        client_channel_print_threads(server->arg1, server->arg2,
        strtol(server->arg3, NULL, 0), server->arg4, server->arg5);
        i = i + 2;
    }
    client_channel_print_threads(server->arg1, server->arg2,
        strtol(server->arg3, NULL, 0), server->arg4, server->arg5);
}

void create_reply(char *buffer, receive_t *server, int j)
{
    list_of_four_argument(3, server, buffer);
    if (j == 13)
        client_print_reply_created(server->arg1, server->arg2,
        strtol(server->arg3, NULL, 0), server->arg4);
    if (j == 23)
        client_event_thread_reply_received(server->arg1, server->arg2,
        server->arg3, server->arg4);
}

void create_thread(char *buffer, receive_t *server, int j)
{
    list_of_five_argument(3, server, buffer);
    if (j == 12)
        client_print_thread_created(server->arg1, server->arg2,
        strtol(server->arg3, NULL, 0), server->arg4, server->arg5);
    if (j == 22)
        client_event_thread_created(server->arg1, server->arg2,
        strtol(server->arg3, NULL, 0), server->arg4, server->arg5);
    if (j == 19)
        client_print_thread(server->arg1, server->arg2,
        strtol(server->arg3, NULL, 0), server->arg4, server->arg5);
}

void create_team_or_channel(char *buffer, receive_t *server, int j)
{
    list_of_three_argument(3, server, buffer);
    if (j == 10)
        client_print_team_created(server->arg1, server->arg2, server->arg3);
    if (j == 11)
        client_print_channel_created(server->arg1, server->arg2, server->arg3);
    if (j == 20)
        client_event_team_created(server->arg1, server->arg2, server->arg3);
    if (j == 21)
        client_event_channel_created(server->arg1, server->arg2, server->arg3);
    if (j == 17)
        client_print_team(server->arg1, server->arg2, server->arg3);
    if (j == 18)
        client_print_channel(server->arg1, server->arg2, server->arg3);
}
