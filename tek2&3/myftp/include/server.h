/*
** EPITECH PROJECT, 2022
** server
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <unistd.h>

typedef struct ftp_struct ftp_t;
struct ftp_struct{
    char *user;
    char *password;
    struct sockaddr_in add;
    struct sockaddr_in addr;
    int s;
    int d;
    int data;
    int port;
    char *current;
    int log;
};

int define_password(int control, ftp_t *base, char *buf, int l);
int define_user(int control, ftp_t *base, char *buf, int l);
int go_parent_directory(int control, ftp_t *base,int);
int loop(ftp_t);
int simple_loop(ftp_t);
char *identify(int l, char *buf);
int only_digits(const char* s);
int write_good_command(int control, ftp_t*);
int delete_file(int control, ftp_t *base, int l, char *buf);
int where_i_am(int control, ftp_t *base);
char *identify_for_3(int l, char *buf);
int move_directory(int control, ftp_t *base, char *buf, int l);

#endif
