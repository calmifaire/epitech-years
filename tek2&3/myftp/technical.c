/*
** EPITECH PROJECT, 2022
** technical function
** File description:
** only
*/

#include "./include/server.h"

char *identify_for_3(int l, char *buf)
{
    char *tmp = malloc(sizeof(char)*l);
    int j = 0;

    for (int i = 4; i != l - 2; i++, j++)
        tmp[j] = buf[i];
    return (tmp);
}

char *identify(int l, char *buf)
{
    char *tmp = malloc(sizeof(char)*l);
    int j = 0;

    for (int i = 5; i != l - 2; i++, j++)
        tmp[j] = buf[i];
    return (tmp);
}

int only_digits(const char* s)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] < '0' || s[i] > '9')
            return (84);
    return (0);
}

int write_good_command(int control, ftp_t *base)
{
    if (base->log == 2)
        write(control, "200 Command okay.\n", 18);
    else
        write(control, "530 Not logged in.\n", 19);
    return (1);
}
