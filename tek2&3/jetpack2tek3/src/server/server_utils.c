/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** server_utils
*/

#include "../include/server.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void check_case(int y, int x, core_t *core, client_t *temp)
{
    if (!(y >= 0 && y < core->height_map && x >= 0 &
    & x <= core->width_map)) return;
    if (core->map_array[y][x] == 'c') {
        core->map_array[y][x] = '_';
        send_coin(temp, x, y);
    }
}

void check_collision_coin_p1(client_t *temp, core_t *core)
{
    if (temp->next != NULL && temp->player_pos_x > 1) {
        bool x = check_float(temp->player_pos_x);
        bool y = check_float(temp->player_pos_y);
        check_case((core->height_map - (int)temp->player_pos_y - 1),
        (int)temp->player_pos_x, core, temp);
        if (x == true)
            check_case((core->height_map - (int)temp->player_pos_y - 1),
            temp->player_pos_x + 1, core, temp);
        if (y == true)
            check_case((core->height_map - (int)temp->player_pos_y - 2),
            temp->player_pos_x, core, temp);
        if (y == true && x == true)
            check_case((core->height_map - (int)temp->player_pos_y - 2),
            temp->player_pos_x + 1, core, temp);
    }

}

void check_collision_coin_p2(client_t *temp, core_t *core)
{
    if (temp->next != NULL && temp->player_pos_x > 1) {
        bool x = check_float(temp->next->player_pos_x);
        bool y = check_float(temp->next->player_pos_y);
        check_case_p2((core->height_map - (int)temp->next->player_pos_y
        - 1), (int)temp->next->player_pos_x, core, temp);
        if (x == true)
            check_case_p2((core->height_map - (int)temp->next->
            player_pos_y - 1),
            temp->next->player_pos_x + 1, core, temp);
        if (y == true)
            check_case_p2((core->height_map - (int)temp->next->player_pos_y
            - 2), temp->next->player_pos_x, core, temp);
        if (y == true && x == true)
            check_case_p2((core->height_map - (int)temp->next->player_pos_y
            - 2), temp->next->player_pos_x + 1, core, temp);
    }
}

void handling_client_read_and_write(core_t *core, client_t *temp, clock_t *time)
{
    check_read_from_client(core, temp);
    if (((clock() - *time)) >= 80000) {
        temp = core->clients;
        while (temp) {
            if (FD_ISSET(temp->fd, &core->server->write_group)) {
                send_start(temp, core);
                send_pos_player1(temp);
                send_pos_player2(temp, core);
                check_collision_coin_p1(temp, core);
                check_collision_coin_p2(temp, core);
                send_finish_no_win(temp, core);
                send_finish_player2_win(temp, core);
                send_finish_player1_win(temp, core);
                send_finish_end_of_map(temp, core);
            }
            temp = temp->next;
        } if (list_size(core->clients) == 2)
            update(&core->clients);
        *time = clock();
    }
}

void start_serveur(core_t *core)
{
    int id = 1;
    init_socket(core->server);
    client_t *temp = core->clients;
    clock_t start = clock();
    while (1) {
        temp = core->clients;
        update_fd_sets(core);
        if (select(FD_SETSIZE, &core->server->read_group,
        &core->server->write_group, NULL, NULL) < 0) {
            fprintf(stderr, "Failed to select\n");
            exit(84);
        }
        if (FD_ISSET(core->server->server_fd, &core->server->read_group)) {
            accept_client(core, id);
            ++id;
        } else {
            handling_client_read_and_write(core, temp, &start);
        }
    }
}