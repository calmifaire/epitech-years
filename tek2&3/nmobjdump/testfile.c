/*
** EPITECH PROJECT, 2022
** testfile
** File description:
** testfile
*/

#include "./include/nm.h"

char *define_array(char *array, FILE *f)
{
    long fSize;

    fseek(f, 0, SEEK_END);
    fSize = ftell(f);
    rewind(f);
    array = (char *) malloc(fSize + 1);
    fread(array, sizeof(char), 4, f);
    return array;
}

int testfile(char *a)
{
    FILE *f;
    char *array;
    unsigned char t[4] = {0x7f, 0x45, 0x4c, 0x46};

    f = fopen(a, "rb");
    if (f == NULL){
        fprintf(stderr, "'%s' No such file\n",a);
        exit(84);
    }
    array = define_array(array, f);
    if (memcmp(array, t, 4) != 0){
        fprintf(stderr, "%s file format not recognized\n",a);
        free(array);
        fclose(f);
        return (84);
    }
    free(array);
    fclose(f);
    return (0);
}
