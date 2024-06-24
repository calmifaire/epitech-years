/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-nykyta.kudrya
** File description:
** code_receive
*/

#include "myteams_client.h"

void process_code(int j, char *buffer, receive_t *server)
{
    if (j == 1 || j == 2 || j == 7 || j == 9)
        write_login_or_sub_event(buffer, server, j);
    if (j == 3 || j == 4)
        write_users(buffer, server, j);
    if (j == 5)
        got_a_text(buffer, server);
    if (j == 6)
        get_message_list(buffer, server);
    if (j == 8 || j == 14)
        listing_team_or_channel(buffer, server, j);
    if (j == 10 || j == 11 || j == 20 || j == 21 || j == 17 || j == 18)
        create_team_or_channel(buffer, server, j);
    if (j == 12 || j == 22 || j == 19)
        create_thread(buffer, server, j);
    if (j == 13 || j == 23)
        create_reply(buffer, server, j);
    if (j == 15)
        listing_thread(buffer, server);
    if (j == 16)
        listing_reply(buffer, server);
}

void get_code(char *buffer, receive_t *server)
{
    int j;
    int i;

    for (i = 0; buffer[i] != '\n'; i++)
        server->code[i] = buffer[i];
    server->code[i] = '\0';
    j = atoi(server->code);
    if (j > 40)
        process_error_info(j, buffer, server);
    else
        process_code(j, buffer, server);
}
