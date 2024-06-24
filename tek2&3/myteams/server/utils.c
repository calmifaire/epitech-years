/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** utils
*/

#include "myteams_server.h"
#include "data.h"

int get_length_to_line_return(char *ptr)
{
    int i = 0;

    for (; ptr[i] != '\0' && ptr[i] != '\n'; i++);
    if (ptr[i] == '\n')
        return (i);
    return (-1);
}

int get_length_to_str(char *ptr, char *str)
{
    int i = 0;
    int len = strlen(str);
    int ptr_len = strlen(ptr);

    for (; ptr[i] != '\0' && len + i < ptr_len; i++) {
        if (strncmp(ptr + i, str, len) == 0)
            return (i);
    }
    return (-1);
}

int get_length_to_line_return2(char *ptr)
{
    int i = 0;

    for (; ptr[i] != '\0' && ptr[i] != '\n'; i++);
    return (i);
}

int get_length_to_char(char *ptr, char c)
{
    int i = 0;

    for (; ptr[i] != '\0' && ptr[i] != c; i++);
    return (i);
}

void init_struct(myserver_t *mys)
{
    mys->clients_arr = malloc(sizeof(client_t) * (MAX_CONNECTIONS + 1));

    memset(mys->clients_arr, 0, sizeof(client_t) * (MAX_CONNECTIONS + 1));
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        mys->clients_arr[i].fd = -1;
        mys->clients_arr[i].use_ctx.num = NO_USE;
    }
    init_save_filesystem(mys);
}

void set_all_fds(fd_set *to_set, myserver_t *mys, int *maxfd)
{
    int det_max = mys->fd;
    FD_ZERO(to_set);
    FD_SET(mys->fd, to_set);
    for (int i = 0; i < MAX_CONNECTIONS && mys->clients_arr[i].fd != -1; i++) {
        FD_SET(mys->clients_arr[i].fd, to_set);
        if (mys->clients_arr[i].fd > det_max)
            det_max = mys->clients_arr[i].fd;
    }
    det_max += 1;
    *maxfd = det_max;
}

void append_to_socket_list(int fd, myserver_t *mys)
{
    int i = 0;

    for (; i < MAX_CONNECTIONS && mys->clients_arr[i].fd != -1; i++);
    if (i == MAX_CONNECTIONS) {
        fprintf(stdout, "Too many connections...\n");
    }
    mys->clients_arr[i].fd = fd;
}
