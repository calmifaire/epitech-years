/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** myteams_server
*/

#pragma once
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <fcntl.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <errno.h>
#include <netinet/ip.h>
#include <uuid/uuid.h>
#include "../libs/myteams/logging_server.h"

enum MY_CONST {
    MAX_PORT = 65535,
    MAX_CONNECTIONS = 10,
    AM_CMD = 14,
    LOGIN = 1
};

enum USE_CONTEXT {
    NO_USE = 15,
    TEAM = 16,
    TEAM_CHAN = 17,
    TEAM_CHAN_THREAD = 18
};

typedef struct client_s client_t;
typedef struct myserver_s myserver_t;
typedef struct packet_s packet_t;

struct packet_s {
    int num;
    char *arg1;
    char *arg2;
    char *arg3;
};

struct client_s {
    int fd;
    char *cl_uuid;
    uuid_t raw_uuid;
    char *name;
    struct sockaddr_in st;
    int is_logged_in;
    myserver_t *mys;
    packet_t use_ctx;
};

struct myserver_s {
    int fd;
    struct sockaddr_in server;
    char *home_dir;
    client_t *clients_arr;
    char *users_txt;
    client_t *all_users_arr;
};

void set_all_fds(fd_set *to_set, myserver_t *mys, int *maxfd);
void init_struct(myserver_t *mys);
void start_server(myserver_t *mys);
void append_to_socket_list(int fd, myserver_t *mys);
int get_length_to_str(char *ptr, char *str);
void *safe_malloc(size_t s);
void convert_to_packet(char *cmd, packet_t *pt);
int count_char_occurence(char *ptr, char c);

char **str_to_word_array(char c, char *str);
void strip_command(char **cmd);
void print_dc_array(char **cmd);

void help(myserver_t *mys, client_t *cl, packet_t *pt);
void login(myserver_t *mys, client_t *cl, packet_t *pt);
void logout(myserver_t *mys, client_t *cl, packet_t *pt);
void users(myserver_t *mys, client_t *cl, packet_t *pt);
void user(myserver_t *mys, client_t *cl, packet_t *pt);

void send_f(myserver_t *mys, client_t *cl, packet_t *pt);
void messages(myserver_t *mys, client_t *cl, packet_t *pt);
void subscribe(myserver_t *mys, client_t *cl, packet_t *pt);
void subscribed(myserver_t *mys, client_t *cl, packet_t *pt);
void unsubscribe(myserver_t *mys, client_t *cl, packet_t *pt);

void use(myserver_t *mys, client_t *cl, packet_t *pt);
void create(myserver_t *mys, client_t *cl, packet_t *pt);
void info(myserver_t *mys, client_t *cl, packet_t *pt);
void list(myserver_t *mys, client_t *cl, packet_t *pt);
