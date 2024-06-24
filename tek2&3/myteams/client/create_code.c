/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-nykyta.kudrya
** File description:
** create_code
*/

#include "myteams_client.h"

void find_code_create(server_t *client, char *buffer)
{
    if (client->use < 2) {
        strcat(client->message, "11\n");
        find_argument(1,buffer,client);
        strcat(client->message,client->arg);
        find_argument(3,buffer,client);
        strcat(client->message,client->arg);
    } else {
        strcat(client->message, "12\n");
        find_argument(1,buffer,client);
        strcat(client->message,client->arg);
    }
    dprintf(client->fd, "%s\n", client->message);
}

void find_code_send(server_t *client, char *buffer)
{
    strcat(client->message, "5\n");
    find_argument(1,buffer,client);
    strcat(client->message,client->arg);
    find_argument(3,buffer,client);
    strcat(client->message,client->arg);
    dprintf(client->fd, "%s\n", client->message);
}

void find_code_use_argu(server_t *client, char *buffer, int n)
{
    if (n == 0){
        dprintf(client->fd, "%s\n", client->message);
        return;
    }
    find_argument(1,buffer,client);
    strcat(client->message,client->arg);
    if (n == 1){
        dprintf(client->fd, "%s\n", client->message);
        return;
    }
    find_argument(3,buffer,client);
    strcat(client->message,client->arg);
    if (n == 2){
        dprintf(client->fd, "%s\n", client->message);
        return;
    }
    find_argument(5,buffer,client);
    strcat(client->message,client->arg);
    dprintf(client->fd, "%s\n", client->message);
}

void find_code_one_argu(server_t *client, char *command, char *buffer)
{
    if (strncmp(command,"/user",5) == 0)
        strcat(client->message, "4\n");
    if (strncmp(command,"/login",6) == 0)
        strcat(client->message, "1\n");
    if (strncmp(command,"/messages",9) == 0)
        strcat(client->message, "6\n");
    if (strncmp(command,"/subscribed",11) == 0)
        strcat(client->message, "9\n");
    if (strncmp(command,"/subscribe",10) == 0 &&
    strncmp(command,"/subscribed",11) != 0)
        strcat(client->message, "7\n");
    if (strncmp(command,"/unsubscribe",12) == 0)
        strcat(client->message, "10\n");
    find_argument(1,buffer,client);
    strcat(client->message,client->arg);
    dprintf(client->fd, "%s\n", client->message);
}

void find_code_no_argu(server_t *client, char *command)
{
    if (strcmp(command,"/logout\0") == 0)
        strcat(client->message, "2\n\0");
    if (strcmp(command,"/users\0") == 0)
        strcat(client->message, "3\n\0");
    if (strcmp(command,"/info\0") == 0)
        strcat(client->message, "14\n\0");
    if (strcmp(command,"/list\0") == 0)
        strcat(client->message, "13\n\0");
    if (strcmp(command,"/subscribed\0") == 0)
        strcat(client->message, "8\n\0");
    dprintf(client->fd, "%s\n", client->message);
}
