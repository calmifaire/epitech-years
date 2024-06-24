/*
** EPITECH PROJECT, 2022
** check
** File description:
** argument number correct
*/

#include "myteams_client.h"

void check_command_other_2(char *buffer, server_t *client, char *command)
{
    if (strncmp(command,"/create",7) == 0) {
        check_create(client,buffer);
        free(command);
        return;
    }
    if (strncmp(command,"/help",5) == 0 &&
    check_argument_number(buffer) == 0) {
        give_help();
        free(command);
        return;
    }
    printf("Unknow command or missing argument, enter \"/help\" if needed\n");
}

void check_command_other(char *buffer, server_t *client, char *command)
{
    if (strncmp(command,"/send",5) == 0 &&
    check_argument_number(buffer) == 2) {
        check_send(client,buffer);
        free(command);
        return;
    }
    if (strncmp(command,"/use",4) == 0 && strncmp(command,"/user",5) != 0) {
        check_use(client,buffer);
        free(command);
        return;
    }
    check_command_other_2(buffer, client, command);
}

void check_command_one_argument(char *buffer, server_t *client, char *command)
{
    if ((strncmp(command,"/user",5) == 0 && strcmp(command,"/users\0") != 0)
        || strncmp(command,"/login",6) == 0
        || strncmp(command,"/messages",9) == 0
        || strncmp(command,"/subscribed",11) == 0
        || strncmp(command,"/subscribe",10) == 0
        || strncmp(command,"/unsubscribe",12) == 0) {
        if (check_argument_number(buffer) == 1) {
            it_command_loggin(command, client, buffer);
            free(command);
            return;
        }
    }
    check_command_other(buffer, client, command);
}

void check_command_of_no_argument(char *buffer, server_t *client)
{
    char *command;

    buffer = trimwhitespace(buffer);
    command = get_command(buffer);
    if (strcmp(command,"/logout\0") == 0 || strcmp(command,"/users\0") == 0 ||
        strcmp(command,"/info\0") == 0 || strcmp(command,"/list\0") == 0 ||
        strcmp(command,"/subscribed\0") == 0) {
            if (check_argument_number(buffer) == 0) {
                find_code_no_argu(client, command);
                free(command);
                return;
            }
    }
    check_command_one_argument(buffer, client, command);
}
