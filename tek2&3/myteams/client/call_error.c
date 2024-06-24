/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-nykyta.kudrya
** File description:
** call_error
*/

#include "myteams_client.h"

void find_error(int j, receive_t *server)
{
    if (j == 41)
        client_error_unknown_team(server->arg1);
    if (j == 42)
        client_error_unknown_channel(server->arg1);
    if (j == 43)
        client_error_unknown_thread(server->arg1);
    if (j == 44)
        client_error_unknown_user(server->arg1);
}

void process_error_info(int j, char *buffer, receive_t *server)
{
    if (j == 45) {
        client_error_unauthorized();
        return;
    }
    if (j == 46) {
        client_error_already_exist();
        return;
    }
    one_argument_send_by_server(buffer, server);
    if (server->arg1 != NULL) {
        find_error(j, server);
    }
}
