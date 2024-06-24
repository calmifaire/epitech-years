/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** retrieve_users2
*/

#include "myteams_server.h"
#include "data.h"

int calc_all_users_str_len(myserver_t *mys)
{
    int to_ret = 0;

    to_ret += strlen("3\n");
    for (int i = 0; mys->all_users_arr[i].fd != -1; i++) {
        to_ret += strlen(mys->all_users_arr[i].cl_uuid);
        to_ret += strlen("\n");
        to_ret += strlen(mys->all_users_arr[i].name);
        to_ret += strlen("\n");
        to_ret += 1;
        to_ret += strlen("\n\n");
    }
    to_ret += 5;
    return (to_ret);
}

void print_all_users_at_start(myserver_t *mys)
{
    for (int i = 0; mys->all_users_arr[i].fd != -1; i++) {
        server_event_user_loaded(mys->all_users_arr[i].cl_uuid, 
            mys->all_users_arr[i].name);
    }
}

void debug_print_all_login_users_fd(client_t *clients_arr)
{
    for (int i = 0; i < MAX_CONNECTIONS && clients_arr[i].fd != -1; i++) {
        printf("Client %s uuid %s fd %d\n", clients_arr[i].name, clients_arr[i].cl_uuid, clients_arr[i].fd);
    }
}

int get_logged_in_user_fd(char *uuid, myserver_t *mys)
{
    int i = 0;

    for (; i < MAX_CONNECTIONS && (mys->clients_arr[i].cl_uuid == NULL ||
        strcmp(mys->clients_arr[i].cl_uuid, uuid) != 0); i++);
    //printf("Get logged in for uuid %s user %s got des %d\n", mys->clients_arr[i].cl_uuid,mys->clients_arr[i].name, mys->clients_arr[i].fd);
    return (mys->clients_arr[i].fd);
}

void notify_all_logged_in_users(myserver_t *mys, char *notify_txt)
{
    for (int i = 0; i < MAX_CONNECTIONS && mys->clients_arr[i].fd != -1; i++) {
        if (mys->clients_arr[i].is_logged_in == 1) {
            //dprintf(mys->clients_arr[i].fd, "%s\n", notify_txt);
            write(mys->clients_arr[i].fd, notify_txt, strlen(notify_txt));
        }
    }
    free(notify_txt);
}

void notify_all_except(myserver_t *mys, client_t *ignored, char *notify_txt)
{
    for (int i = 0; i < MAX_CONNECTIONS && mys->clients_arr[i].fd != -1; i++) {
        if (mys->clients_arr[i].is_logged_in == 1 &&
            strcmp(mys->clients_arr[i].cl_uuid, ignored->cl_uuid) != 0) {
            write(mys->clients_arr[i].fd, notify_txt, strlen(notify_txt));
        }
    }
}
