/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** in_game_message
*/

#include "../include/client.h"

void get_coin(client_t *client)
{
    int x;
    int y;
    int ok = 0;
    coin_t *coin = client->coin_list->first;

    client->receive = next_word(client->receive);
    client->receive = next_word(client->receive);
    x = atoi(client->receive);
    client->receive = next_word(client->receive);
    y = atoi(client->receive);
    while (coin != NULL && ok == 0) {
        if (coin->map_x == x && coin->map_y == y)
            ok = 1;
        else
            coin = coin->next;
    }
    if (coin != NULL)
        coin->color = sfBlue;
}

void get_player(client_t *client)
{
    client->receive = next_word(client->receive);
    if (atoi(client->receive) == client->player1->id) {
        client->receive = next_word(client->receive);
        client->player1->x = atof(client->receive);
        client->receive = next_word(client->receive);
        client->player1->y = atof(client->receive);
        client->receive = next_word(client->receive);
        client->player1->score = atoi(client->receive);
    } else if (atoi(client->receive) != client->player1->id) {
        client->receive = next_word(client->receive);
        client->player2->x = atof(client->receive);
        client->receive = next_word(client->receive);
        client->player2->y = atof(client->receive);
        client->receive = next_word(client->receive);
        client->player2->score = atoi(client->receive);
    }
}

void end_result(client_t *client)
{
    client->receive = next_word(client->receive);
    if (atoi(client->receive) == -1)
        printf("no winner\n");
    else if (atoi(client->receive) == client->player1->id)
        printf("YOU WIN\n");
    else
        printf("You lost\n");
}

void check_game(client_t *client)
{
    int i;

    for (i = 0; client->receive[i] != '\0'; i++)
        if (client->receive[i] == '\n')
            client->receive[i] = ' ';
    if (strncmp(client->receive, "PLAYER ", 7) == 0)
        get_player(client);
    if (strncmp(client->receive, "COIN ", 5) == 0)
        get_coin(client);
    if (strncmp(client->receive, "FINISH ", 7) == 0) {
        client->finish = true;
        end_result(client);
    }
    for (i = 0; client->receive[i] != ' '
    && client->receive[i] != '\0'; i++);
    if (client->receive[i + 1] != '\0') {
        client->receive = next_word(client->receive);
        check_game(client);
    }
}