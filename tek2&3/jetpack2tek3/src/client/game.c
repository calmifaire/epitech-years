/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** game
*/

#include "../include/client.h"

void new_wall(client_t *client, int i, int j, graphic_t *game)
{
    wall_t *new = malloc(sizeof(wall_t));
    if (game->wall_list == NULL || new == NULL)
        free_all(client, 84);
    new->object = sfRectangleShape_create();
    new->x = j * (1600 / client->width);
    new->y = i * (600 / client->height);
    new->pos.x = new->x;
    new->pos.y = new->y;
    new->color = sfCyan;
    new->next = game->wall_list->first;
    game->wall_list->first = new;
}

void new_coin(client_t *client, int i, int j)
{
    coin_t *new = malloc(sizeof(*new));
    if (client->coin_list == NULL || new == NULL)
        free_all(client, 84);
    new->object = sfRectangleShape_create();
    new->x = j * (1600 / client->width);
    new->y = i * (600 / client->height);
    new->map_x = j;
    new->map_y = i;
    new->pos.x = new->x;
    new->pos.y = new->y;
    new->color = sfYellow;
    new->next = client->coin_list->first;
    client->coin_list->first = new;
}

void init_game(graphic_t *game, client_t *client)
{
    game->wall_list = init_list(client);
    client->coin_list = init_list_coin(client);
    game->player1 = sfRectangleShape_create();
    game->player2 = sfRectangleShape_create();
    game->ok = 0;
    sfRectangleShape_setFillColor(game->player1, sfGreen);
    sfRectangleShape_setFillColor(game->player2, sfRed);
    sem_wait(&client->semaphore_graphic);
}

void give_value(graphic_t *game, client_t *client)
{
    game->size.x = 1600 / client->width;
    game->size.y = 600 / client->height;
    sfRectangleShape_setSize(game->player1, game->size);
    sfRectangleShape_setSize(game->player2, game->size);
    game->player1_pos.x = client->player1->x * (1600 / client->width);
    game->player1_pos.y = 600 - (client->player1->y
    * (600 / client->height)) - game->size.y;
    game->player2_pos.x = client->player2->x * (1600 / client->width);
    game->player2_pos.y = 600 - (client->player2->y
    * (600 / client->height)) - game->size.y;
    for (int i = 0; i != client->height; i++)
        for (int j = 0; j != client->width; j++) {
            if (client->map[i][j] == 'e')
                new_wall(client, i, j, game);
            if (client->map[i][j] == 'c')
                new_coin(client, i, j);
        }
}

void *graphic(client_t *client)
{
    graphic_t game;
    sfVideoMode mode = {1600, 600, 32};

    init_game(&game, client);
    init_text(&game, client);
    give_value(&game, client);
    game.window = sfRenderWindow_create(mode, "Jetpack ride", sfClose, NULL);
    if (!game.window)
        free_all(client, 84);
    while (sfRenderWindow_isOpen(game.window)) {
        while (sfRenderWindow_pollEvent(game.window, &game.event)) {
            if (game.event.type == sfEvtClosed || client->finish == true)
                sfRenderWindow_close(game.window);
            if (game.event.type == sfEvtKeyPressed)
                check_keypress(&game, client);
            if (game.event.type == sfEvtKeyReleased)
                check_keyrelease(&game, client);
        } update_game(&game, client);
    } free_game(&game, client);
    pthread_exit(NULL);
}