/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** map
*/

#include "../include/client.h"

void init_map(client_t *client)
{
    int j = 0;
    int k = 0;

    client->map = malloc(sizeof(char *)*client->height);
    if (!client->map)
        free_all(client, 84);
    for (int i = 0; i != client->height; i++) {
        client->map[i] = malloc(sizeof(char)*client->width + 2);
        if (!client->map[i])
            free_all(client, 84);
        client->map[i][0] = '\0';
    }
    for (int i = 0; i != client->height * client->width; i++){
        if (k == client->width && j != client->height - 1) {
            client->map[j][k + 1] = '\0';
            k = 0;
            j++;
        }
        client->map[j][k] = client->cells[i];
        k++;
        client->map[j][k] = '\0';
    };
}