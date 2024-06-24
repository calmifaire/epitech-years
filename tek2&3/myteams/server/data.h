/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** data
*/

#pragma once
#include "myteams_server.h"

int get_length_to_line_return(char *ptr);
int get_length_to_line_return2(char *ptr);
int get_length_to_char(char *ptr, char c);
client_t retrieve_saved_user(myserver_t *mys, char *name, char *uuid);
void init_save_filesystem(myserver_t *mys);
void load_users(myserver_t *mys);
void append_user(myserver_t *mys, client_t *cl);
int is_user_logged_in(myserver_t *mys, char *uuid);
void load_users_array(myserver_t *mys);
int calc_all_users_str_len(myserver_t *mys);
void print_all_users_at_start(myserver_t *mys);
void save_message(myserver_t *mys, client_t *cl, packet_t *pt);
int get_logged_in_user_fd(char *uuid, myserver_t *mys);
void debug_print_all_login_users_fd(client_t *clients_arr);
char *get_ptr_to_conversations(myserver_t *mys, client_t *cl, packet_t *pt);
void rearrange_clients(client_t *client_array);
void notify_all_logged_in_users(myserver_t *mys, char *notify_txt);
void notify_all_except(myserver_t *mys, client_t *ignored, char *notify_txt);
