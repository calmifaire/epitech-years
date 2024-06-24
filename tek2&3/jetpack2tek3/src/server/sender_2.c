/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** sender_2
*/

#include "../include/server.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void send_finish_no_win(client_t *temp, core_t *core)
{
    if (temp->player_pos_x >= 1 && temp->next != NULL && core->map_array
    [core->height_map - (int)temp->player_pos_y - 1]
    [(int)temp->player_pos_x + 1] == 'e'
    && core->map_array[core->height_map - (int)temp->next->player_pos_y - 1]
    [(int)temp->next->player_pos_x + 1] == 'e') {
        char *res = fill_str("FINISH ");
        res = my_strcat2(res, "-1", 0);
        res = my_strcat2(res, "\n", 0);
        write(temp->fd, res, strlen(res));
        write(temp->next->fd, res, strlen(res));
        free(res);
        exit(0);
    }
}

void send_finish_player2_win(client_t *temp, core_t *core)
{
    if (temp->player_pos_x >= 1 && temp->next != NULL && core->map_array
    [core->height_map - (int)temp->player_pos_y - 1]
    [(int)temp->player_pos_x + 1] == 'e' && core->map_array
    [core->height_map - (int)temp->next->player_pos_y - 1]
    [(int)temp->next->player_pos_x + 1] != 'e') {
        char *res = fill_str("FINISH ");
        res = my_strcat2(res, my_itoa(temp->next->ID), 1);
        res = my_strcat2(res, "\n", 0);
        write(temp->fd, res, strlen(res));
        write(temp->next->fd, res, strlen(res));
        free(res);
        exit(0);
    }
}

void send_finish_player1_win(client_t *temp, core_t *core)
{
    if (temp->player_pos_x >= 1 && temp->next != NULL && core->map_array
    [core->height_map - (int)temp->player_pos_y - 1]
    [(int)temp->player_pos_x + 1] != 'e' && core->map_array
    [core->height_map - (int)temp->next->player_pos_y - 1]
    [(int)temp->next->player_pos_x + 1] == 'e') {
        char *res = fill_str("FINISH ");
        res = my_strcat2(res, my_itoa(temp->ID), 1);
        res = my_strcat2(res, "\n", 0);
        write(temp->fd, res, strlen(res));
        write(temp->next->fd, res, strlen(res));
        free(res);
        exit(0);
    }
}

void concat_win_coin_p1(client_t *temp)
{
    char *res = fill_str("FINISH ");

    if (temp->score > temp->next->score) {
        res = my_strcat2(res, my_itoa(temp->ID), 1);
        res = my_strcat2(res, "\n", 0);
        write(temp->fd, res, strlen(res));
        write(temp->next->fd, res, strlen(res));
        free(res);
        exit(0);
    }
}