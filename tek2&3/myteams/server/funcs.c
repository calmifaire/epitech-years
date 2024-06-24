/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** funcs
*/

#include "myteams_server.h"
#include "data.h"

void help(myserver_t *mys, client_t *cl, packet_t *pt)
{
    if (cl->is_logged_in == 0) {
       dprintf(cl->fd, "0\n0\n");
    } else {
       dprintf(cl->fd, "0\n1\n");
    }
}

void login(myserver_t *mys, client_t *cl, packet_t *pt)
{
    client_t searched_user;
    char *notify_txt = NULL;

    if (cl->is_logged_in == 1)
        return;
    searched_user = retrieve_saved_user(mys, pt->arg1, NULL);
    if (searched_user.cl_uuid == NULL) {
        cl->cl_uuid = safe_malloc(sizeof(char) * 37);
        uuid_generate(cl->raw_uuid);
        uuid_unparse(cl->raw_uuid, cl->cl_uuid);
        server_event_user_created(cl->cl_uuid, pt->arg1);
        cl->name = pt->arg1;
        append_user(mys, cl);
    } else {
        if (is_user_logged_in(mys, searched_user.cl_uuid) == 1) {
            dprintf(cl->fd, "46\n");
            return;
        }
        cl->cl_uuid = searched_user.cl_uuid;
    }
    cl->name = strdup(pt->arg1);
    cl->is_logged_in = 1;
    server_event_user_logged_in(cl->cl_uuid);
    load_users_array(mys);
    asprintf(&notify_txt, "1\n%s\n%s\n", cl->cl_uuid, cl->name);
    notify_all_logged_in_users(mys, notify_txt);
}

void logout(myserver_t *mys, client_t *cl, packet_t *pt)
{
    char *notify_txt = NULL;
    if (cl->is_logged_in == 0)
        return;
    server_event_user_logged_out(cl->cl_uuid);
    asprintf(&notify_txt, "2\n%s\n%s\n", cl->cl_uuid, cl->name);
    notify_all_logged_in_users(mys, notify_txt);
    cl->is_logged_in = 0;
    cl->name = NULL;
    cl->cl_uuid = NULL;
    cl->use_ctx.num = NO_USE;
    load_users_array(mys);
}

void users(myserver_t *mys, client_t *cl, packet_t *pt)
{
    char *to_send = safe_malloc(sizeof(char) * calc_all_users_str_len(mys));
    char *to_cat;

    load_users_array(mys);
    to_send[0] = '\0';
    strcat(to_send, "3\n");
    for (int i = 0; mys->all_users_arr[i].fd != -1; i++) {
        strcat(to_send, mys->all_users_arr[i].cl_uuid);
        strcat(to_send, "\n");
        strcat(to_send, mys->all_users_arr[i].name);
        strcat(to_send, "\n");
        to_cat = (mys->all_users_arr[i].is_logged_in == 1) ? "1" : "0";
        strcat(to_send, to_cat);
        if (mys->all_users_arr[i + 1].fd != -1)
            strcat(to_send, "\n\n");
    }
    strcat(to_send, "\n");
    write(cl->fd, to_send, strlen(to_send));
}

void user(myserver_t *mys, client_t *cl, packet_t *pt)
{
    client_t searched_user = retrieve_saved_user(mys, NULL, pt->arg1);

    if (searched_user.cl_uuid == NULL) {
        dprintf(cl->fd, "44\n%s\n", pt->arg1);
        return;
    }
    if (is_user_logged_in(mys, pt->arg1)) {
        dprintf(cl->fd, "4\n%s\n%s\n%d\n", searched_user.cl_uuid, searched_user.name, 1);
    } else if (searched_user.cl_uuid != NULL) {
        dprintf(cl->fd, "4\n%s\n%s\n%d\n", searched_user.cl_uuid, searched_user.name, 0);
    }
}
