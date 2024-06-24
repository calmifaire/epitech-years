/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** game_update
*/

#include "../include/client.h"

void check_keypress(graphic_t *game, client_t *client)
{
    if (game->event.key.code == sfKeySpace && game->ok == 0) {
        write(client->fd, "FIRE 1\n", 7);
        game->ok = 1;
    }
}

void check_keyrelease(graphic_t *game, client_t *client)
{
    if (game->event.key.code == sfKeySpace && game->ok == 1) {
        write(client->fd, "FIRE 0\n", 7);
        game->ok = 0;
    }
}

void update_move(graphic_t *game, client_t *client)
{
    game->player1_pos.x = client->player1->x * (1600 / client->width);
    game->player1_pos.y = 600 - (client->player1->y
    * (600 / client->height)) - game->size.y;
    game->player2_pos.x = client->player2->x * (1600 / client->width);
    game->player2_pos.y = 600 - (client->player2->y
    * (600 / client->height)) - game->size.y;
}

void update_game(graphic_t *game, client_t *client)
{
    char *cptr = my_itoa(client->player1->score);
    update_move(game, client);
    sfText_setString(game->cptr, cptr);
    sfRenderWindow_clear(game->window, sfBlue);
    draw_all(game, client);
    sfRenderWindow_display(game->window);
    free(cptr);
}
