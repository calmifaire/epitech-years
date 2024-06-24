/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** utils_concat
*/

#include "../include/server.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *concat_param_player1(char *positions, client_t **temp)
{
    char buf_x[100];
    char buf_y[100];
    positions = fill_str("PLAYER ");
    positions = my_strcat2(positions, my_itoa((*temp)->ID), 1);
    positions = my_strcat2(positions, " ", 0);
    gcvt((*temp)->player_pos_x, 6, buf_x);
    positions = my_strcat2(positions, buf_x, 0);
    positions = my_strcat2(positions, " ", 0);
    gcvt((*temp)->player_pos_y, 6, buf_y);
    positions = my_strcat2(positions, buf_y, 0);
    positions = my_strcat2(positions, " ", 0);
    positions = my_strcat2(positions, my_itoa((*temp)->score), 1);
    positions = my_strcat2(positions, "\n", 0);
    return (positions);
}

char *concat_param_player2(char *positions, client_t **temp)
{
    char buf_x[100];
    char buf_y[100];
    positions = fill_str("PLAYER ");
    positions = my_strcat2(positions, my_itoa((*temp)->next->ID), 1);
    positions = my_strcat2(positions, " ", 0);
    gcvt((*temp)->next->player_pos_x, 6, buf_x);
    positions = my_strcat2(positions, buf_x, 0);
    positions = my_strcat2(positions, " ", 0);
    gcvt((*temp)->next->player_pos_y, 6, buf_y);
    positions = my_strcat2(positions, buf_y, 0);
    positions = my_strcat2(positions, " ", 0);
    positions = my_strcat2(positions, my_itoa((*temp)->next->score), 1);
    positions = my_strcat2(positions, "\n", 0);
    return (positions);
}

char *concat_param_player2_last(char *positions, client_t **temp)
{
    char buf_x[100];
    char buf_y[100];
    positions = fill_str("PLAYER ");
    positions = my_strcat2(positions, my_itoa((*temp)->ID), 1);
    positions = my_strcat2(positions, " ", 0);
    gcvt((*temp)->player_pos_x, 6, buf_x);
    positions = my_strcat2(positions, buf_x, 0);
    positions = my_strcat2(positions, " ", 0);
    gcvt((*temp)->player_pos_y, 6, buf_y);
    positions = my_strcat2(positions, buf_y, 0);
    positions = my_strcat2(positions, " ", 0);
    positions = my_strcat2(positions, my_itoa((*temp)->score), 1);
    positions = my_strcat2(positions, "\n", 0);
    return (positions);
}

char *concat_param_player1_last(char *positions, client_t **temp)
{
    char buf_x[100];
    char buf_y[100];
    positions = fill_str("PLAYER ");
    positions = my_strcat2(positions, my_itoa((*temp)->prev->ID), 1);
    positions = my_strcat2(positions, " ", 0);
    gcvt((*temp)->prev->player_pos_x, 6, buf_x);
    positions = my_strcat2(positions, buf_x, 0);
    positions = my_strcat2(positions, " ", 0);
    gcvt((*temp)->prev->player_pos_y, 6, buf_y);
    positions = my_strcat2(positions, buf_y, 0);
    positions = my_strcat2(positions, " ", 0);
    positions = my_strcat2(positions, my_itoa((*temp)->prev->score), 1);
    positions = my_strcat2(positions, "\n", 0);
    return (positions);
}

int list_size(client_t *client)
{
    client_t *temp = client;
    int counter = 0;
    while (temp) {
        ++counter;
        temp = temp->next;
    }
    return (counter);
}