/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** draw_object
*/

#include "../include/client.h"

void draw_coin(client_t *client, graphic_t *game)
{
    coin_t *coin = client->coin_list->first;

    while (coin->next != NULL) {
        sfRectangleShape_setSize(coin->object, game->size);
        sfRectangleShape_setFillColor(coin->object, coin->color);
        sfRectangleShape_setPosition(coin->object, coin->pos);
        sfRenderWindow_drawRectangleShape(game->window, coin->object, NULL);
        coin = coin->next;
    }
}

void draw_wall(graphic_t *game)
{
    wall_t *wall = game->wall_list->first;

    while (wall->next != NULL) {
        sfRectangleShape_setSize(wall->object, game->size);
        sfRectangleShape_setFillColor(wall->object, wall->color);
        sfRectangleShape_setPosition(wall->object, wall->pos);
        sfRenderWindow_drawRectangleShape(game->window, wall->object, NULL);
        wall = wall->next;
    }
}

void draw_text(graphic_t *game)
{
    sfRenderWindow_drawText(game->window, game->score, NULL);
    sfRenderWindow_drawText(game->window, game->cptr, NULL);
}

void draw_all(graphic_t *game, client_t *client)
{
    draw_coin(client, game);
    draw_wall(game);
    draw_text(game);
    sfRectangleShape_setPosition(game->player2, game->player2_pos);
    sfRenderWindow_drawRectangleShape(game->window, game->player2, NULL);
    sfRectangleShape_setPosition(game->player1, game->player1_pos);
    sfRenderWindow_drawRectangleShape(game->window, game->player1, NULL);
}