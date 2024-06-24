/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** manage_args
*/


#include "myteams_server.h"
#include "data.h"

int count_char_occurence(char *ptr, char c)
{
    int count = 0;

    for (int i = 0; ptr[i] != '\0'; i++) {
        if (ptr[i] == c)
            count++;
    }
    return (count);
}

void convert_to_packet(char *cmd, packet_t *pt)
{
    int arg_len = count_char_occurence(cmd, '\n');
    char **split_cmd = str_to_word_array('\n', cmd);

    split_cmd[arg_len] = NULL;
    pt->num = atoi(split_cmd[0]);
    pt->arg1 = (arg_len >= 2) ? split_cmd[1] : NULL;
    pt->arg2 = (arg_len >= 3) ? split_cmd[2] : NULL;
    pt->arg3 = (arg_len >= 4) ? split_cmd[3] : NULL;
}
