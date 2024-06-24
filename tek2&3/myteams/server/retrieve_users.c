/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** retrieve_data
*/

#include "myteams_server.h"
#include "data.h"

client_t retrieve_saved_user(myserver_t *mys, char *name, char *uuid)
{
    client_t to_ret = {0};
    int i = 0;
    
    for (; mys->all_users_arr[i].fd != -1; i++) {
        if (name != NULL && strcmp(mys->all_users_arr[i].name, name) == 0) {
            return (mys->all_users_arr[i]);
        }
        if (uuid != NULL && strcmp(mys->all_users_arr[i].cl_uuid, uuid) == 0) {
            return (mys->all_users_arr[i]);
        }
    }
    return (to_ret);
}

void fill_users_array(myserver_t *mys)
{
    client_t to_ret = {0};
    char *cur_line = NULL;
    int it = 0;
    int line_length = 0;
    int colon_length = 0;
    int cl_index = 0;
    
    if (mys->users_txt[0] == '\0')
        return;
    while (it < strlen(mys->users_txt)) {  
        line_length = 
                get_length_to_str(mys->users_txt + it, "\n\n");
        if (line_length == -1)
            line_length = get_length_to_char(mys->users_txt + it, '\n');
        cur_line = 
            malloc(sizeof(char) * (line_length + 1));
        if (!cur_line)
            exit(84);
        strncpy(cur_line, mys->users_txt + it, line_length);
        cur_line[line_length] = '\0';
        colon_length = get_length_to_char(mys->users_txt + it, ':');
        cur_line[colon_length] = '\0';
        to_ret.cl_uuid = cur_line;
        to_ret.name = cur_line + colon_length + 1;
        mys->all_users_arr[cl_index].cl_uuid = to_ret.cl_uuid;
        mys->all_users_arr[cl_index].name = to_ret.name;
        mys->all_users_arr[cl_index].is_logged_in = is_user_logged_in(mys, to_ret.cl_uuid);
        if (is_user_logged_in(mys, to_ret.cl_uuid))
            mys->all_users_arr[cl_index].fd = get_logged_in_user_fd(to_ret.cl_uuid, mys);
        cl_index++;
        it += line_length + strlen("\n\n");
    }
}

void append_user(myserver_t *mys, client_t *cl)
{
    struct stat st;

    stat("./save/users/users.txt", &st);
    int fd = open("./save/users/users.txt", O_WRONLY | O_APPEND);
    if (st.st_size == 0) {
        dprintf(fd, "%s:%s\n", cl->cl_uuid, cl->name);
        close(fd);
        load_users(mys);
        load_users_array(mys);
        return;
    }
    dprintf(fd, "\n%s:%s\n", cl->cl_uuid, cl->name);
    load_users(mys);
    load_users_array(mys);
    close(fd);
}

void list_all_users(myserver_t *mys)
{
}

int get_am_of_users(myserver_t *mys)
{
    int check = 0;
    int ret = 0;

    if (strlen(mys->users_txt) == 0)
        return (0);    
    for (int i = 0; mys->users_txt[i] != '\0'; i++) {
        if (mys->users_txt[i] == '\n')
            check++;
        if (check == 2) {
            check = 0;
            ret++;
        }
    }
    return (ret + 1);
}

void print_all_users_array(myserver_t *mys)
{
    for (int i = 0; mys->all_users_arr[i].fd != -1; i++) {
        printf("User %s uuid %s st %d\n", mys->all_users_arr[i].name, mys->all_users_arr[i].cl_uuid, mys->all_users_arr[i].is_logged_in);
    }
}

void load_users_array(myserver_t *mys)
{
    int am_users = get_am_of_users(mys);

    if (mys->all_users_arr != NULL)
        free(mys->all_users_arr);
    mys->all_users_arr = safe_malloc(sizeof(client_t) * (am_users + 1));
    memset(mys->all_users_arr, 0, sizeof(client_t) * (am_users + 1));
    fill_users_array(mys);
    mys->all_users_arr[am_users].fd = -1;
}

int is_user_logged_in(myserver_t *mys, char *uuid)
{
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (mys->clients_arr[i].cl_uuid != NULL && 
            strcmp(mys->clients_arr[i].cl_uuid, uuid) == 0) {
            return (1);
        }
    }
    return (0);
}
