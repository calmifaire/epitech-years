/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-nykyta.kudrya
** File description:
** command_precise
*/

#include "myteams_client.h"

void give_help(void)
{
    printf("/login [\"user_name\"] : set the user_name used by client\n\
/logout : disconnect the client from the server\n\
/users : get the list of all users that exist on the domain\n\
/user [\"user_uuid\"] : get information about a user\n\
/send [\"user_uuid\"] [\"message_body\"] : send a message to a user\n\
/messages [\"user_uuid\"] : list all messages exchange with an user\n\
/subscribe [\"team_uuid\"] : subscribe to the event of a team and its sub\n\
directories (enable reception of all events from a team)\n\
/subscribed ?[\"team_uuid\"] : list all subscribed teams or list all users\n\
subscribed to a team\n\
/unsubscribe [\"team_uuid\"] : unsubscribe from a team\n\
/use ?[\"team_uuid\"] ?[\"channel_uuid\"] ?[\"thread_uuid\"] : \n\
use specify a context team/channel/thread\n\
/create : based on what is being used create the sub resource\n\
/list : based on what is being used list all the sub resources\n\
/info : based on what is being used list the current\n");
}

void check_use(server_t *client, char *buffer)
{
    int i = check_argument_number(buffer);

    if (i > 3 || i < 0)
        return;
    if (i == 0)
        strcat(client->message, "15\n");
    if (i == 1)
        strcat(client->message, "16\n");
    if (i == 2)
        strcat(client->message, "17\n");
    if (i == 3)
        strcat(client->message, "18\n");
    if (i < 2)
        client->use = 0;
    else
        client->use = i - 1;
    find_code_use_argu(client, buffer, i);
}

void check_send(server_t *client, char *buffer)
{
    int i;
    int j;

    for (i = 0; buffer[i] != '\"'; i++);
    i++;
    for (; buffer[i] != '\"'; i++);
    i++;
    for (; buffer[i] != '\"'; i++);
    i++;
    for (j = 0; buffer[i] != '\"'; i++)
        j++;
    if (j > MAX_BODY_LENGTH)
        return;
    find_code_send(client,buffer);
}

void it_command_loggin(char *command, server_t *client, char *buffer)
{
    int i;
    int j;

    if (strncmp(command,"/login",6) != 0) {
        find_code_one_argu(client, command, buffer);
        return;
    }
    for (i = 0; buffer[i] != '\"'; i++);
    i++;
    for (j = 0; buffer[i] != '\"'; i++)
        j++;
    if (j > MAX_NAME_LENGTH)
        return;
    find_code_one_argu(client, command, buffer);
}
