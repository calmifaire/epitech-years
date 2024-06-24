/*
** EPITECH PROJECT, 2022
** command
** File description:
** command
*/

#include "./include/server.h"

int where_i_am(int control, ftp_t *base)
{
    char *code = malloc(sizeof(char)*(strlen(base->current)+18));

    code[0] = '\0';
    if (base->log != 2)
        write(control, "530 Not logged in.\n", 19);
    else{
        strcat(code, "257 \"");
        strcat(code, base->current);
        strcat(code, "\" created.\n");
        write(control, code, strlen(code));
    }
    free(code);
    return (1);
}

int define_password(int control, ftp_t *base, char *buf, int l)
{
    int i = 0;
    char *name = malloc(sizeof(char)*l);

    if (l - 2 == 5 && strcmp(base->user, "Anonymous") == 0){
        write(control, "230 User logged in, proceed.\n", 29);
        base->log = 2;
        return (1);
    }else{
        write(control, "530 Not logged in.\n", 19);
        return (1);
    }
    write(control, "501 Syntax error in parameters or argument.\n", 44);
    return (1);
}

int define_user(int control, ftp_t *base, char *buf, int l)
{
    int i = 0;

    if (l - 2 >= 5){
        base->user = identify(l, buf);
        base->log = 1;
        write(control, "331 User name okay, need password.\n", 35);
    }else
        write(control, "501 Syntax error in parameters or argument.\n", 44);
    return (1);
}

static void change_path(ftp_t *base, int control)
{
    int	i = 0;
    int	j = 0;

    for	(j = 0; base->current[j] != '\0' && base->current[j] != '\n'; j++)
        if (base->current[j] == '/')
            i++;
    if (i >= 2){
        for (;base->current[j] != '/'; j--);
        base->current[j] = '\0';
    }
    if (i == 1){
        for (;base->current[j - 1] != '/'; j--);
        base->current[j] = '\0';
    }
}

int go_parent_directory(int control, ftp_t *base, int i)
{
    if (base->log != 2)
        write(control, "530 Not logged in.\n", 19);
    else if (i - 2 > 4)
        write(control, "501 Syntax error in parameters or argument.\n", 44);
    else{
        change_path(base, control);
        write_good_command(control, base);
    }
    return (1);
}
