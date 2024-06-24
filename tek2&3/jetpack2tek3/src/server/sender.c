/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** sender
*/

#include "../include/server.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void send_start(client_t *temp, core_t *core)
{
    if (list_size(core->clients) == 2 && (temp->player_is_ready ==
    true && temp->player_is_ready == true) && temp->game_start == false) {
        write(temp->fd, "START\n", 6);
        temp->game_start = true;
    }
}

void send_pos_player1(client_t *temp)
{
    if (temp->next != NULL && temp->game_start == true &&
    temp->next->game_start == true) {
        char *positions = NULL;
        positions = concat_param_player1(positions, &temp);
        write(temp->fd, positions, strlen(positions));
        free(positions);
        positions = concat_param_player2(positions, &temp);
        write(temp->fd, positions, strlen(positions));
        free(positions);
    }
}

void send_pos_player2(client_t *temp, core_t *core)
{
    if (temp->next == NULL && list_size(core->clients) == 2 &&
    (temp->game_start == true && temp->prev->game_start == true)) {
        char *positions = NULL;
        positions = concat_param_player2_last(positions, &temp);
        write(temp->fd, positions, strlen(positions));
        free(positions);
        positions = concat_param_player1_last(positions, &temp);
        write(temp->fd, positions, strlen(positions));
        free(positions);
    }
}

void send_coin(client_t *temp, int x, int y)
{
    temp->score += 5;
    char *player_coin = fill_str("COIN ");
    player_coin = my_strcat2(player_coin, my_itoa(temp->ID), 1);
    player_coin = my_strcat2(player_coin, " ", 0);
    player_coin = my_strcat2(player_coin, my_itoa(x), 1);
    player_coin = my_strcat2(player_coin, " ", 0);
    player_coin = my_strcat2(player_coin, my_itoa(y), 1);
    player_coin = my_strcat2(player_coin, "\n", 0);
    write(temp->fd, player_coin, strlen(player_coin));
    write(temp->next->fd, player_coin, strlen(player_coin));
    free(player_coin);
}

void send_coin_player2(client_t *temp, int x, int y)
{
    temp->next->score += 5;
    char *player_coin = fill_str("COIN ");
    player_coin = my_strcat2(player_coin, my_itoa(temp->next->ID), 1);
    player_coin = my_strcat2(player_coin, " ", 0);
    player_coin = my_strcat2(player_coin, my_itoa(x), 1);
    player_coin = my_strcat2(player_coin, " ", 0);
    player_coin = my_strcat2(player_coin, my_itoa(y), 1);
    player_coin = my_strcat2(player_coin, "\n", 0);
    write(temp->next->fd, player_coin, strlen(player_coin));
    write(temp->fd, player_coin, strlen(player_coin));
    free(player_coin);
}
