/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** utils_sender
*/

#include "../include/server.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void concat_win_coin_p2(client_t *temp)
{
    char *res = fill_str("FINISH ");

    if (temp->score < temp->next->score) {
        res = my_strcat2(res, my_itoa(temp->next->ID), 1);
        res = my_strcat2(res, "\n", 0);
        write(temp->fd, res, strlen(res));
        write(temp->next->fd, res, strlen(res));
        free(res);
        exit(0);
    }
}

void concat_win_no_p(client_t *temp)
{
    char *res = fill_str("FINISH ");

    if (temp->score == temp->next->score) {
        res = my_strcat2(res, "-1", 0);
        res = my_strcat2(res, "\n", 0);
        write(temp->fd, res, strlen(res));
        write(temp->next->fd, res, strlen(res));
        free(res);
        exit(0);
    }
}

void send_finish_end_of_map(client_t *temp, core_t *core)
{
    if (temp->next != NULL && (int)temp->player_pos_x
    >= core->width_map && temp->next != NULL) {
        concat_win_coin_p1(temp);
        concat_win_coin_p2(temp);
        concat_win_no_p(temp);
    }
}