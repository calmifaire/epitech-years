/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** main
*/

#include "myteams_client.h"

void print_usage(void)
{
    printf("USAGE: ./myteams_cli ip port\n   ");
    printf("ip is the server ip address on which the server socket listens");
    printf("\n  port is the port number on which the server socket listens");
    printf("\n");
}

int create_socket(server_t *client)
{
    int enable = 1;

    if ((client->fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
        return (fprintf(stdout, "Socket init error\n"), 0);
    if (setsockopt(client->fd, SOL_SOCKET, SO_REUSEADDR, &enable,
    sizeof(int)) == -1)
        return (fprintf(stdout, "Failed to set socket options\n"), 0);
    if ((connect(client->fd, (struct sockaddr*)&client->server,
    sizeof(client->server))) < 0)
        return (fprintf(stdout, "Connect fail\n"), 0);
    return (1);
}

int get_socket_params(int ac, char **av, server_t *client)
{
    int port;
    char *check_err = NULL;

    port = (int) strtol(av[2], &check_err, 10);
    if ((check_err && *check_err != '\0') || port <= 0) {
        print_usage();
        return (0);
    }
    client->server.sin_port = htons(atoi(av[2]));
    client->server.sin_family = AF_INET;
    client->use = 0;
    client->message = malloc(sizeof(char) * 1000);
    client->arg = malloc(sizeof(char) * 1000);
    if (!client->message || !client->arg)
        return (0);
    if (inet_pton(AF_INET, av[1], &client->server.sin_addr) <= 0) {
        printf("invalid IP\n");
        return (0);
    }
    return (1);
}

int initialize_receive_struct(receive_t *server)
{
    server->code = malloc(sizeof(char) * 6);
    server->arg1 = malloc(sizeof(char) * 37);
    server->arg2 = malloc(sizeof(char) * MAX_BODY_LENGTH);
    server->arg3 = malloc(sizeof(char) * MAX_BODY_LENGTH);
    server->arg4 = malloc(sizeof(char) * MAX_BODY_LENGTH);
    server->arg5 = malloc(sizeof(char) * MAX_BODY_LENGTH);
    if (!server->code || !server->arg1 || !server->arg2 || !server->arg3
    || !server->arg4 || !server->arg5)
        return (0);
    server->code[0] = '\0';
    server->arg1[0] = '\0';
    server->arg2[0] = '\0';
    server->arg3[0] = '\0';
    server->arg4[0] = '\0';
    server->arg5[0] = '\0';
    return (1);
}

int main(int ac, char **av)
{
    server_t client = {0};
    receive_t server = {0};

    if (ac != 3 || (ac == 2 && strcmp(av[1], "-help") == 0))
        return (print_usage(), 0);
    if (get_socket_params(ac, av, &client) == 0 || create_socket(&client) == 0
    || initialize_receive_struct(&server) == 0)
        return (84);
    loop_client(&client, &server);
    printf("conection closed by server ending process\n");
    free(client.message);
    free(client.arg);
    free(server.code);
    free(server.arg1);
    free(server.arg2);
    free(server.arg3);
    free(server.arg4);
    free(server.arg5);
    return (0);
}
