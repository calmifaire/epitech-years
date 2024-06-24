/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** init_text
*/

#include "../include/client.h"

char *my_revstr(char *str)
{
    char temp = 0;
    int len = strlen(str) - 1;

    for (int i = 0; i < len; ++i) {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        --len;
    }
    return (str);
}

int my_int_len(int nb)
{
    int counter = 0;

    if (nb == 0)
        return (1);
    if (nb < 0)
        return (84);

    while (nb > 0) {
        ++counter;
        nb /= 10;
    }
    return (counter);
}

char *my_itoa(int nbr)
{
    int sign = 0;
    int i = 0;

    if (nbr < 0) {
        sign = 1;
        nbr *= -1;
    }
    int len = my_int_len(nbr);
    char *res = malloc(sizeof(char) * (len + 1));
    res[len] = 0;

    for (; i != len; ++i) {
        res[i] = nbr % 10 + 48;
        nbr /= 10;
    }
    if (sign == 1)
        res[i] = '-';
    my_revstr(res);
    return (res);
}

void init_text(graphic_t *game, client_t *client)
{
    game->position_score.x = 0;
    game->position_score.y = 0;
    game->position_cptr.x = 100;
    game->position_cptr.y = 0;
    sfColor color;
    color = sfBlack;
    game->score = sfText_create();
    game->cptr = sfText_create();
    game->font = sfFont_createFromFile("ka1.ttf");
    sfText_setFont(game->score, game->font);
    sfText_setFont(game->cptr, game->font);
    sfText_setString(game->score, "score :");
    sfText_setColor(game->score, color);
    sfText_setColor(game->cptr, color);
    sfText_setCharacterSize(game->score, 20);
    sfText_setCharacterSize(game->cptr, 20);
    sfText_setPosition(game->score, game->position_score);
    sfText_setPosition(game->cptr, game->position_cptr);
}