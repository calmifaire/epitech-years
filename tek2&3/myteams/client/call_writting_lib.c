/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-nykyta.kudrya
** File description:
** call_writting_lib
*/

#include "myteams_client.h"

void listing_team_or_channel(char *buffer, receive_t *server, int j)
{
    int i = 2;

    if (j != 8)
        i++;
    while ((i = list_of_three_argument(i, server, buffer)) != 0) {
        if (j == 8)
            client_print_teams(server->arg1, server->arg2, server->arg3);
        else
            client_team_print_channels(server->arg1,server->arg2,server->arg3);
        i = i + 2;
    }
    if (j == 8)
        client_print_teams(server->arg1, server->arg2, server->arg3);
    else
        client_team_print_channels(server->arg1, server->arg2, server->arg3);
}

void get_message_list(char *buffer, receive_t *server)
{
    int i = 2;

    while ((i = list_of_three_argument(i, server, buffer)) != 0) {
        client_private_message_print_messages(server->arg1,
        strtol(server->arg2, NULL, 0), server->arg3);
        i = i + 2;
    }
    client_private_message_print_messages(server->arg1,
    strtol(server->arg2, NULL, 0), server->arg3);
}

void got_a_text(char *buffer, receive_t *server)
{
    argument_one_send_by_server(buffer, server);
    two_argument_send_by_server(buffer, server);
    client_event_private_message_received(server->arg1, server->arg2);
}

void write_users(char *buffer, receive_t *server, int j)
{
    int i = 2;

    if (j == 3) {
        while ((i = list_of_three_argument(i, server, buffer)) != 0) {
            client_print_users(server->arg1, server->arg2, atoi(server->arg3));
            i = i + 2;
        }
    } else
        list_of_three_argument(i, server, buffer);
    client_print_users(server->arg1, server->arg2, atoi(server->arg3));
}

void write_login_or_sub_event(char *buffer, receive_t *server, int j)
{
    argument_one_send_by_server(buffer, server);
    two_argument_send_by_server(buffer, server);
    if (j == 1)
        client_event_logged_in(server->arg1, server->arg2);
    if (j == 2)
        client_event_logged_out(server->arg1, server->arg2);
    if (j == 7)
        client_print_subscribed(server->arg1, server->arg2);
    if (j == 9)
        client_print_unsubscribed(server->arg1, server->arg2);
}
