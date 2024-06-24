/*
** EPITECH PROJECT, 2022
** command part2
** File description:
** part2
*/

#include "./include/server.h"

int move_directory(int control, ftp_t *base, char *buf, int l)
{
    char *path = malloc(sizeof(char)*(l - 2 + strlen(base->current)));

    path[0] = '\0';
    if (base->log == 2 && l - 2 >= 5){
        strcat(path, base->current);
        if (path[strlen(path) - 1] != '/')
            strcat(path, "/"); 
        buf = identify_for_3(l, buf);
        strcat(path, buf);
        if (access(path, 0) == 0){
            base->current = path;
            write(control, "250 Requested file action okay, completed.\n", 43);
        }
        else
            write(control, "550 Requête non exécutée : Fichier indisponible.\n", 52);
    }else if (base->log != 2)
        write(control, "530 Not logged in.\n", 19);
    else
        write(control, "501 Syntax error in parameters or argument.\n", 44);
    return (1);
}

int delete_file(int control, ftp_t *base, int l, char *buf)
{
    char *path = malloc(sizeof(char)*(l - 2 + strlen(base->current)));

    if (base->log == 2 && l - 2 >= 5){
        strcat(path, base->current);
        strcat(path, "/"); 
        buf = identify(l, buf);
        strcat(path, buf);
        if (remove(path) == 0){
            write(control, "250 Requested file action okay, completed.\n", 43);
        }
        else
            write(control, "550 Requête non exécutée : Fichier indisponible.\n", 52);
    }else if (base->log != 2)
        write(control, "530 Not logged in.\n", 19);
    else
        write(control, "501 Syntax error in parameters or argument.\n", 44);
    free(path);
    return (1);
}
