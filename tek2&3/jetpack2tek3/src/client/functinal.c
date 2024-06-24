/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** functinal
*/

#include "../include/client.h"

void free_game(graphic_t *game, client_t *client)
{
    sfRectangleShape_destroy(game->player1);
    sfRectangleShape_destroy(game->player2);
    sfText_destroy(game->score);
    sfText_destroy(game->cptr);
    sfFont_destroy(game->font);
    free_wall_list(game);
    free_coin_list(client);
    sfRenderWindow_destroy(game->window);
}

void free_all(client_t *client, int code)
{
    free(client->command);
    free(client->receive);
    if (client->cells)
        free(client->cells);
    if (client->map != NULL) {
        for (int i = 0; i != client->height && client->map[i] != NULL; i++)
            free(client->map[i]);
        free(client->map);
    }
    if (client->player1 != NULL)
        free(client->player1);
    if (client->player2 != NULL)
        free(client->player2);
    if (code != 0)
        exit(code);
}

char *next_word(char *str)
{
    int i = 0;
    int j = 0;

    for (;str[i] != ' ' && str[i] != '\0'; i++);
    if (str[i] == '\0')
        return (NULL);
    for (;str[i] == ' ' && str[i] != '\0'; i++);
    if (str[i] == '\0')
        return (NULL);
    for (;str[i] != '\0'; i++) {
        str[j] = str[i];
        j++;
    }
    str[j] = '\0';
    return (str);
}

int get_height(client_t *client)
{
    int i = 0;
    char *tmp = malloc(sizeof(char)* 100);

    for (;client->receive[i] != ' ' && client->receive[i] != '\0'; i++);
    for (;client->receive[i] == ' ' && client->receive[i] != '\0'; i++);
    for (int j = 0;client->receive[i] != ' '
    && client->receive[i] != '\0'; i++) {
        tmp[j] = client->receive[i];
        j++;
        tmp[j + 1] = '\0';
    }
    client->height = atoi(tmp);
    free(tmp);
    return (i);
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
    return (str);
}