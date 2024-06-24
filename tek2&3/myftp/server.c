/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "./include/server.h"

int loop(ftp_t base)
{
    while (1)
        simple_loop(base);
    close(base.s);
    return (0);
}

static int create_binding(ftp_t base)
{
    int b;
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(base.port);
    addr.sin_addr.s_addr = INADDR_ANY;
    base.addr = addr;
    b = bind(base.s, (struct sockaddr*) &base.addr, sizeof(base.addr));
    if (b == -1){
        fprintf(stderr, "bind fail\n");
        return (84);
    }
    if (listen(base.s, 10) == -1){
        fprintf(stderr, "listen fail\n");
        return (84);
    }
    return (loop(base));
}

int main(int ac, char **av)
{
    ftp_t base;

    if (ac != 3)
        return (84);
    base.s = socket(AF_INET, SOCK_STREAM, 0);
    if (base.s == -1){
        fprintf(stderr, "socket fail\n");
        return (84);
    }
    if (only_digits(av[1]) == 84)
        return (84);
    if (access(av[2], 0) == -1)
        return (84);
    base.current = av[2];
    base.port = atoi(av[1]);
    base.log = 0;
    return (create_binding(base));
}
