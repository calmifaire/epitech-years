/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** server
*/

#include "myteams_server.h"
#include "data.h"

static const void (*all_funcs[]) (myserver_t *mys, client_t *cl, packet_t *pt) = {
    help, login, logout, users, user, send_f, messages, subscribe, subscribed, subscribed,
    unsubscribe, create, create, list, info, use, use, use, use
};

void handle_clients(myserver_t *mys)
{
}

int read_from_socket(myserver_t *mys, client_t *cl, char *cmd)
{
    int i = read(cl->fd, cmd, 100);

    if (i == 0) {
        close(cl->fd);
        memset(cl, 0, sizeof(client_t));
        cl->use_ctx.num = NO_USE;
        cl->fd = -1;
        rearrange_clients(mys->clients_arr);
        return (0);
    }
    if (i < 0) {
        return (0);
    }
    if (cmd[i - 2] == '\r')
        cmd[i - 2] = '\0';
    if (cmd[i - 1] == '\n')
        cmd[i - 1] = '\0';
    cmd[i] = '\0';
    return (1);
}

void pointer_to_function(myserver_t *mys, client_t *cl, packet_t *pt)
{
    all_funcs[pt->num](mys, cl, pt);
}

void request_handler(myserver_t *mys, client_t *cl)
{
    char *cmd = safe_malloc(2048);
    packet_t pt = {0};

    cmd[0] = '\0';
    if (read_from_socket(mys, cl, cmd) == 0)
        return;
    convert_to_packet(cmd, &pt);
    if (cl->is_logged_in) {
        pointer_to_function(mys, cl, &pt);
    } else if (pt.num == LOGIN) {
        pointer_to_function(mys, cl, &pt);
    } else {
        dprintf(cl->fd, "45\n");
    }
    free(cmd);
}

void check_all_reads(myserver_t *mys, fd_set *readfds)
{
    for (int i = 0; i < MAX_CONNECTIONS && mys->clients_arr[i].fd != -1; i++) {
        if (FD_ISSET(mys->clients_arr[i].fd, readfds)) {
            request_handler(mys, &mys->clients_arr[i]);
        }
    }
}

void start_server(myserver_t *mys)
{
    int select_ret = 0;
    int maxfd;
    fd_set readfds;
    int accept_fd;

    while (1) {
        set_all_fds(&readfds, mys, &maxfd);
        if ((select_ret = select(maxfd, &readfds, NULL, NULL, NULL)) == -1) {
            fprintf(stdout, "Select error\n");
        }
        if (FD_ISSET(mys->fd, &readfds)) {
            accept_fd = accept(mys->fd, NULL, NULL);
            append_to_socket_list(accept_fd, mys);
        }
        check_all_reads(mys, &readfds);
    }
}
