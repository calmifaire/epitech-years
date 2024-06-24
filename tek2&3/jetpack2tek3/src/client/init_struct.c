/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** init_struct
*/

#include "../include/client.h"

void free_coin_list(client_t *client)
{
    coin_t *coin;

    if (client->coin_list->first != NULL) {
            while (client->coin_list->first != NULL) {
            coin = client->coin_list->first;
            sfRectangleShape_destroy(coin->object);
            client->coin_list->first = client->coin_list->first->next;
            free(coin);
        }
        free(client->coin_list);
    }
}

void free_wall_list(graphic_t *game)
{
    wall_t *wall;

    if (game->wall_list->first != NULL) {
        while (game->wall_list->first != NULL) {
            wall = game->wall_list->first;
            sfRectangleShape_destroy(wall->object);
            game->wall_list->first = game->wall_list->first->next;
            free(wall);
        }
        free(game->wall_list);
    }
}

coin_list_t *init_list_coin(client_t *client)
{
    coin_list_t *list = malloc(sizeof(coin_list_t));
    coin_t *coin = malloc(sizeof(coin_t));

    if (list == NULL || coin == NULL)
        free_all(client, 84);
    coin->object = sfRectangleShape_create();
    coin->x = 0;
    coin->y = 0;
    coin->map_x = 0;
    coin->map_y = 0;
    coin->pos.x = coin->x;
    coin->pos.y = coin->y;
    coin->color = sfCyan;
    coin->next = NULL;
    list->first = coin;
    return (list);
}

wall_list_t *init_list(client_t *client)
{
    wall_list_t *list = malloc(sizeof(wall_list_t));
    wall_t *wall = malloc(sizeof(wall_t));

    if (list == NULL || wall == NULL)
        free_all(client, 84);
    wall->object = sfRectangleShape_create();
    wall->x = 0;
    wall->y = 0;
    wall->pos.x = wall->x;
    wall->pos.y = wall->y;
    wall->color = sfCyan;
    wall->next = NULL;
    list->first = wall;
    return (list);
}

bool init_string_struct(client_t *client)
{
    client->command = malloc(sizeof(char) * 10);
    if (!client->command)
        return (true);
    client->receive = malloc(sizeof(char) * 6000);
    if (!client->receive) {
        free(client->command);
        return (true);
    }
    client->command[0] = '\0';
    client->receive[0] = '\0';
    client->player1 = malloc(sizeof(player_t));
    client->player2 = malloc(sizeof(player_t));
    client->map = NULL;
    client->player1->id = 0;
    client->ready = false;
    client->start = false;
    client->finish = false;
    return (false);
}