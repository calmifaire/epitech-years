/*
** EPITECH PROJECT, 2022
** utilite
** File description:
** utilite
*/

#include "myteams_client.h"

void find_argument(int i, char *buffer, server_t *client)
{
    int j;
    int nb = 0;

    for (j = 0; buffer[j] != '\0' && nb != i; j++)
        if (buffer[j] == '\"')
            nb++;
    for (nb = 0;buffer[j] != '\"'; j++){
        client->arg[nb] = buffer[j];
        nb++;
    }
    client->arg[nb] = '\n';
    client->arg[nb + 1] = '\0';
}

char *trimwhitespace(char *str)
{
    char *end;

    while (isspace((unsigned char)*str)) str++;
    if (*str == 0)
        return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
    return str;
}

char *get_command(char *str)
{
    int i;
    char *tmp;

    for (i = 0; str[i] != ' '; i++);
    tmp = strndup(str, i);
    return (tmp);
}

float check_argument_number(char *buffer)
{
    int i;
    int nb = 0;
    float n;

    for (i = 0; buffer[i] != ' ' && buffer[i] != '\"' && buffer[i] != '\0';i++);
    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\"')
            nb = nb + 1;
        if (buffer[i] != '\"' && buffer[i] != ' ' && nb % 2 == 0) {
            return (-1);
        }
    }
    n = nb;
    return (n / 2);
}
