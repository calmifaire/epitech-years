/*
** EPITECH PROJECT, 2022
** server side
** File description:
** loop
*/

#include "./include/server.h"

static int command_part2(char* buf, int control, ftp_t *base, int i)
{
    if (strncmp(buf, "CWD", 3) == 0)
        return (move_directory(control, base, buf, i));
    if (strncmp(buf, "QUIT", 4) == 0)
        return (1);
    return (0);
}

static void command(char* buf, int control, ftp_t *base, int i)
{
    int ok = 0;

    if (strncmp(buf, "CDUP", 4) == 0)
        ok = go_parent_directory(control,base,i);
    if (strncmp(buf, "NOOP", 4) == 0)
        ok = write_good_command(control, base);
    if (strncmp(buf, "USER", 4) == 0)
        ok = define_user(control, base, buf, i);
    if (strncmp(buf, "PASS", 4) == 0)
        ok = define_password(control, base, buf, i);
    if (strncmp(buf, "PWD", i - 2) == 0)
        ok = where_i_am(control, base);
    if (strncmp(buf, "DELE", 4) == 0)
        ok = delete_file(control, base, i, buf);
    if (strncmp(buf, "HELP", 4) == 0)
        ok = write(control, "214 Help message.\n", 18);
    if (ok == 0)
        ok = command_part2(buf, control, base, i);
    if (ok == 0)
        write(control, "500 Syntax error, command unrecognized.\n", 40);
}

static void do_child(char* buf, int control, ftp_t base)
{
    int i;

    write(control, "220 Service ready for new user.\n", 32);
    buf[0] = '\0';
    while (strncmp(buf, "QUIT", i - 2) != 0){
        if ((i = read(control, buf, 100)) == -1)
            write(control, "sorry I fail read\n", 18);
        else
            command(buf, control, &base, i);
    }
    write(control, "221 Service closing control connection.\n", 40);
    close(control);
}

static int do_the_fork(int control, ftp_t base)
{
    char *buf = malloc(sizeof(char) * 100);
    int child = fork();

    if (child == -1){
        fprintf(stderr, "fork fail\n");
        return (84);
    }
    if (child == 0)
        do_child(buf, control, base);
    else
        close(control);
    return (0);
}

int simple_loop(ftp_t base)
{
    int g = sizeof(base.add);
    int control;

    control = accept(base.s, (struct sockaddr*) &base.add, &g);
    if (control == -1){
        fprintf(stderr, "accept fail\n");
        exit(84);
    }
    if (do_the_fork(control, base) == 84)
        exit(84);
    return (0);
}
