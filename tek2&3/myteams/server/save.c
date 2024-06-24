/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** save
*/

#include "myteams_server.h"
#include "data.h"

void load_users(myserver_t *mys)
{
    int fd;
    struct stat st;

    if (mys->users_txt != NULL) {
        free(mys->users_txt);
    }
    fd = open("./save/users/users.txt", O_RDONLY | O_CREAT, 0644);
    stat("./save/users/users.txt", &st);
    mys->users_txt = malloc(sizeof(char) * (st.st_size + 1));
    if (!mys->users_txt)
        exit(84);
    read(fd, mys->users_txt, st.st_size);
    mys->users_txt[st.st_size] = '\0';
    close(fd);
}

void init_save_filesystem(myserver_t *mys)
{
    struct stat st;

    if (stat("./save", &st) == -1) {
        mkdir("./save", 0755);
        mkdir("./save/users", 0755);
        mkdir("./save/msgs", 0755);
    }
    load_users(mys);
    load_users_array(mys);
    print_all_users_at_start(mys);
}
