/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** myteams_client
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <uuid/uuid.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <string.h>
#include "../libs/myteams/logging_client.h"

enum CONST {
    MAX_NAME_LENGTH = 32,
    MAX_DESCRIPTION_LENGTH = 255,
    MAX_BODY_LENGTH  = 512,
};

typedef struct server_s server_t;
typedef struct receive_s receive_t;
struct server_s {
    int fd;
    struct sockaddr_in server;
    int use;
    char* message;
    char* arg;
};

struct receive_s {
    char *code;
    char *arg1;
    char *arg2;
    char *arg3;
    char *arg4;
    char *arg5;
};

char *trimwhitespace(char *str);
void loop_client(server_t *client, receive_t *server);
char *get_command(char *str);
float check_argument_number(char *buffer);
void check_command_of_no_argument(char *buffer, server_t *client);
void check_command_one_argument(char *buffer, server_t *client, char *command);
void it_command_loggin(char *command, server_t *client, char *buffer);
void check_send(server_t *client, char *buffer);
void check_use(server_t *client, char *buffer);
void check_create(server_t *client, char *buffer);
void find_code_no_argu(server_t *client, char *command);
void find_code_one_argu(server_t *client, char *command, char *buffer);
void find_argument(int i, char *buffer, server_t *client);
void find_code_send(server_t *client, char *buffer);
void find_code_use_argu(server_t *client, char *buffer, int n);
void find_code_create(server_t *client, char *buffer);
void give_help(void);
void get_code(char *buffer, receive_t *server);
void one_argument_send_by_server(char *buffer, receive_t *server);
void argument_one_send_by_server(char *buffer, receive_t *server);
void two_argument_send_by_server(char *buffer, receive_t *server);
void write_login_or_sub_event(char *buffer, receive_t *server, int j);
void write_users(char *buffer, receive_t *server, int j);
int list_of_three_argument(int i, receive_t *server, char *buffer);
void process_error_info(int j, char *buffer, receive_t *server);
void got_a_text(char *buffer, receive_t *server);
void get_message_list(char *buffer, receive_t *server);
void listing_team_or_channel(char *buffer, receive_t *server, int j);
void create_team(char *buffer, receive_t *server);
int get_four_list(int i, receive_t *server, char *buffer);
int list_of_five_argument(int i, receive_t *server, char *buffer);
int get_three_list(int i, receive_t *server, char *buffer);
int list_of_four_argument(int i, receive_t *server, char *buffer);
int list_of_three_argument(int i, receive_t *server, char *buffer);
void create_reply(char *buffer, receive_t *server, int j);
void create_thread(char *buffer, receive_t *server, int j);
void create_team_or_channel(char *buffer, receive_t *server, int j);
void listing_thread(char *buffer, receive_t *server);
void listing_reply(char *buffer, receive_t *server);
int get_two_list(int i, receive_t *server, char *buffer);
