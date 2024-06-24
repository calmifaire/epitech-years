/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** utils3
*/

#include "myteams_server.h"
#include "data.h"

int is_clients_arr_arranged(client_t *client_array)
{
    int switch_one = 0;

    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (client_array[i].fd == -1)
            switch_one = 1;
        if (switch_one == 1 && client_array[i].fd != -1)
            return (0);
    }
    return (1);

}

void rearrange_clients(client_t *client_array)
{
    client_t *handle = safe_malloc(sizeof(client_t));

    while (is_clients_arr_arranged(client_array) == 0) {
        for (int i = 0; i < MAX_CONNECTIONS - 1; i++) {
            if (client_array[i].fd == -1 && client_array[i + 1].fd != -1) {
                    memcpy(handle, &client_array[i], sizeof(client_t));
                    memcpy(&client_array[i], &client_array[i + 1], sizeof(client_t));
                    memcpy(&client_array[i + 1], handle, sizeof(client_t));
            }
        }
    }
    free(handle);
    debug_print_all_login_users_fd(client_array);
}
