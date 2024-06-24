/*
** EPITECH PROJECT, 2022
** 2d
** File description:
** 1d
*/

#include <stdlib.h>
#include <stdio.h>

void array_1d_to_2d(const int *array, size_t height ,size_t width, int ***res)
{
    int **fake;
    int h = 0;

    *res = (int**)malloc(height * sizeof(int*));
    if (res == NULL)
        exit(84);
    for (int i = 0; i < height; i++)
        (*res)[i] = (int*)malloc(width * sizeof(int));
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++, h++)
            (*res)[i][j] = array[h];
}

void  array_2d_free(int **array , size_t  height , size_t  width)
{
    for (int i = 0; i != height; i++)
        free(array[i]);
    free(array);
}
