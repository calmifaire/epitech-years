/*
** EPITECH PROJECT, 2022
** custom strcmp
** File description:
** strcmp for nm
*/

#include "./include/nm.h"

int go_to_character(int i, char *str)
{
    for (;str[i] != '\0'; i++){
        if (str[i] >= 'A' && str[i] <= 'Z')
            return (i);
        if (str[i] >= 'a' && str[i] <= 'z')
            return (i);
        if (str[i] >= '0' && str[i] <= '9')
            return (i);
    }
    return (i - 1);
}

int test(char s, char c)
{
    if (s >= 'A' && s <= 'Z' && c >= 'A' && c <= 'Z')
        return ((s + 32)-(c + 32));
    if (s >= 'A' && s <= 'Z')
        return (s + 32 - c);
    if (c >= 'A' && c <= 'Z')
        return (s - (c + 32));
    return (s - c);
}

int custom_strcmp(char *str1, char *str2)
{
    int i = 0;
    int j = 0;

    for (; i < strlen(str1) && j < strlen(str2); i++){
        i = go_to_character(i, str1);
        j = go_to_character(j, str2);
        if (test(str1[i], str2[j]) != 0)
            return (test(str1[i], str2[j]));
        j++;
    }
    if (str1[i] != '\0' && str2[j] == '\0')
        return (1);
    if (str1[i] == '\0' && str2[j] == '\0' && j > i)
        return (1);
    return (0);
}
