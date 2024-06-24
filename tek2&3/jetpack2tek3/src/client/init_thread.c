/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** init_thread
*/

#include "../include/client.h"

void init_thread_network_and_graphic(client_t *client)
{
    pthread_create(&client->network, NULL, (void *(*)(void *))set_up, client);
    pthread_create(&client->graphic, NULL, (void *(*)(void *))graphic, client);
    sem_init(&client->semaphore_graphic, 0, 0);
}

void join_network(client_t *client)
{
    pthread_join(client->network, NULL);
}

void join_graphic(client_t *client)
{
    pthread_join(client->graphic, NULL);
}