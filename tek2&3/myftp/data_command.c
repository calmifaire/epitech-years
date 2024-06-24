/*
** EPITECH PROJECT, 2022
** data
** File description:
** command data trnsfert
*/

#include "./include/server.h"

void retrive_file(int control, ftp_t *base, char *buf, int l)
{
    FILE *f;
    long fsize;
    char *string;

    if (l - 2 < 5){
        write(control, "xxx Error (RFC compliant)\n", 26);
        return;
    }
    buf = identify(l, buf);
    f = fopen(buf, "rb");
    fseek(f, 0, SEEK_END);
    fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    string = malloc(fsize + 1);
    fread(string, fsize, 1, f);
    fclose(f);
    string[fsize] = '\0';
    write(base->data, string, fsize);
}
