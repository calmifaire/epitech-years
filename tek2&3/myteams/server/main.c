/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** main
*/

#include "myteams_server.h"

int initialize_server_socket(myserver_t *mys)
{
    int enable = 1;

    if ((mys->fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
        return (fprintf(stdout, "Socket init error\n"), 0);
    if (setsockopt(mys->fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) == -1)
        return (fprintf(stdout, "Failed to set socket options\n"), 0);
    if (bind(mys->fd, (struct sockaddr *) &mys->server, sizeof(mys->server))
        == -1)
        return (fprintf(stdout, "Bind failed.\n"), 0);
    if (listen(mys->fd, MAX_CONNECTIONS) == -1)
        return (fprintf(stdout, "Listen failed..."));
    return (1);
}

void print_usage(void)
{
     printf("USAGE: ./myteams_server port\n\n"
            "\tport is the port number on which the server socket listens\n");
}

int get_data(int ac, char **av, myserver_t *mys)
{
    int port;
    char *check_err = NULL;

    port = (int) strtol(av[1], &check_err, 10);
    if ((check_err && *check_err != '\0') || port >= MAX_PORT || port <= 0) {
        print_usage();
        return (0);
    }
    mys->server.sin_port = htons(atoi(av[1]));
    mys->server.sin_addr.s_addr = INADDR_ANY;
    mys->server.sin_family = AF_INET;
    printf("Listening on port %d...\n", ntohs(mys->server.sin_port));
    return (1);
}

int main(int ac, char **av)
{
    myserver_t mys = {0};
    
    init_struct(&mys);
    if (ac != 2 || (ac == 2 && strcmp(av[1], "-help") == 0))
        return (print_usage(), 0);
    if (get_data(ac, av, &mys) == 0 || initialize_server_socket(&mys) == 0)
        return (84);
    start_server(&mys);
}
