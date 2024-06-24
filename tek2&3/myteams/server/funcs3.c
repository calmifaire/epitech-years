/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** funcs3
*/

#include "myteams_server.h"
#include "data.h"

void use(myserver_t *mys, client_t *cl, packet_t *pt)
{
    cl->use_ctx.num = pt->num;
    cl->use_ctx.arg1 = (pt->arg1 != NULL) ? strdup(pt->arg1) : NULL;
    cl->use_ctx.arg2 = (pt->arg2 != NULL) ? strdup(pt->arg2) : NULL;
    cl->use_ctx.arg3 = (pt->arg3 != NULL) ? strdup(pt->arg3) : NULL;
}

void create(myserver_t *mys, client_t *cl, packet_t *pt)
{
    char *sent_uuid = safe_malloc(sizeof(char) * 37);
    char *sent_uuid2 = safe_malloc(sizeof(char) * 37);
    char *notify_txt = NULL;
    uuid_t u;
    uuid_t u2;

    uuid_generate(u);
    uuid_generate(u2);
    uuid_unparse(u, sent_uuid);
    uuid_unparse(u2, sent_uuid2);
    switch (cl->use_ctx.num) {
        case NO_USE:
            dprintf(cl->fd, "10\n%s\n%s\n%s\n", sent_uuid, pt->arg1, pt->arg2);
            server_event_team_created(sent_uuid, pt->arg1, cl->cl_uuid);
            asprintf(&notify_txt, "20\n%s\n%s\n%s\n", sent_uuid, pt->arg1, pt->arg2);
            notify_all_logged_in_users(mys, notify_txt);
            break;
        case TEAM:
            dprintf(cl->fd, "11\n%s\n%s\n%s\n", sent_uuid, pt->arg1, pt->arg2);
            server_event_channel_created(cl->use_ctx.arg1, sent_uuid, pt->arg1);
            asprintf(&notify_txt, "21\n%s\n%s\n%s\n", sent_uuid, pt->arg1, pt->arg2);
            notify_all_except(mys, cl, notify_txt);
            break;
        case TEAM_CHAN:
            dprintf(cl->fd, "12\n%s\n%s\n%ld\n%s\n%s\n",
                sent_uuid, cl->cl_uuid, time(NULL), pt->arg1, pt->arg2);
            server_event_thread_created(cl->use_ctx.arg1, sent_uuid, cl->cl_uuid, pt->arg1, pt->arg2);
            asprintf(&notify_txt, "22\n%s\n%s\n%ld\n%s\n%s\n",
                sent_uuid, cl->cl_uuid, time(NULL), pt->arg1, pt->arg2);
            notify_all_except(mys, cl, notify_txt);
            break;
        case TEAM_CHAN_THREAD:
            dprintf(cl->fd, "13\n%s\n%s\n%ld\n%s\n",
                cl->use_ctx.arg1, cl->cl_uuid, time(NULL), pt->arg1);
            server_event_reply_created(cl->use_ctx.arg3, cl->cl_uuid, pt->arg1);
            asprintf(&notify_txt, "23\n%s\n%s\n%s\n%s\n", cl->use_ctx.arg1, cl->use_ctx.arg3, cl->cl_uuid, pt->arg1);
            notify_all_except(mys, cl, notify_txt);
            break;
    }
}

void info(myserver_t *mys, client_t *cl, packet_t *pt)
{    
    if (cl->use_ctx.num == NO_USE) {
        dprintf(cl->fd, "4\n%s\n%s\n%d\n", cl->cl_uuid, cl->name, cl->is_logged_in);
    }
}

void list(myserver_t *mys, client_t *cl, packet_t *pt)
{

}
