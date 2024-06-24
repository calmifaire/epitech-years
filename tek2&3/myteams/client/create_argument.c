/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-nykyta.kudrya
** File description:
** create_argument
*/

#include "myteams_client.h"

void check_lenght_body(server_t *client, char *buffer)
{
    int i;
    int j;

    for (i = 0; buffer[i] != '\"'; i++);
    i++;
    for (j = 0; buffer[i] != '\"'; i++)
        j++;
    if (j > MAX_BODY_LENGTH)
        return;
    find_code_create(client,buffer);
}

void check_lenght_name_body(server_t *client, char *buffer)
{
    int i;
    int j;

    for (i = 0; buffer[i] != '\"'; i++)
        ;
    i++;
    for (j = 0; buffer[i] != '\"'; i++)
        j++;
    if (j > MAX_NAME_LENGTH)
        return;
    i++;
    for (; buffer[i] != '\"'; i++)
        ;
    for (j = 0; buffer[i] != '\"'; i++)
        j++;
    if (j > MAX_BODY_LENGTH)
        return;
    find_code_create(client,buffer);
}

void check_lenght_name_description(server_t *client, char *buffer)
{
    int i;
    int j;

    for (i = 0; buffer[i] != '\"'; i++)
        ;
    i++;
    for (j = 0; buffer[i] != '\"'; i++)
        j++;
    if (j > MAX_NAME_LENGTH)
        return;
    i++;
    for (; buffer[i] != '\"'; i++)
        ;
    for (j = 0; buffer[i] != '\"'; i++)
        j++;
    if (j > MAX_DESCRIPTION_LENGTH)
        return;
    find_code_create(client,buffer);
}

void check_create(server_t *client, char *buffer)
{
    int i = check_argument_number(buffer);

    if (i < 1 || i > 2)
        return;
    if (client->use == 0 || client->use == 1) {
        if (i != 2)
            return;
        if (client->use == 0)
            check_lenght_name_description(client, buffer);
        if (client->use == 1)
            check_lenght_name_body(client, buffer);
    }
    if (client->use == 2) {
        if (i != 1)
            return;
        check_lenght_body(client, buffer);
    }
}
