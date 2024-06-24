/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** utils2
*/

#include "myteams_server.h"

int get_char_count(char c, char *str)
{
    int c_count = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            c_count++;
        }
    }
    return (c_count);
}

char **str_to_word_array(char c, char *str)
{
    char **res = malloc(sizeof(char*) * (get_char_count(c, str) + 2));
    res[get_char_count(c, str) + 1] = NULL;
    int len = strlen(str);
    int old_pos = 0;
    int ps = 0;
    
    if (!res)
        exit(84);
    for (int i = 0; i <= len; i++) {
        if (str[i] == c || i == len) {
            str[i] = '\0';
            res[ps++] = str + old_pos;
            old_pos = i + 1;
        }
    }
    return (res);
}

void strip_command(char **cmd)
{
    for (int i = 0; cmd[i] != NULL; i++) {
        if (i > 0) {
            cmd[i] += 1;
            cmd[i][strlen(cmd[i]) - 1] = '\0';
        }
    }
}

void print_dc_array(char **cmd)
{
    for (int i = 0; cmd[i] != NULL; i++) {
        printf("|%s|", cmd[i]);
    }
    printf("\n");
}

void *safe_malloc(size_t s)
{
    void *to_ret = malloc(s);
    if (to_ret == NULL)
        exit(84);
    return (to_ret);
}
