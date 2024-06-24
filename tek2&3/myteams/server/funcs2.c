/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** funcs
*/

#include "myteams_server.h"
#include "data.h"

void send_f(myserver_t *mys, client_t *cl, packet_t *pt)
{
    client_t searched_user = retrieve_saved_user(mys, NULL, pt->arg1);

    if (searched_user.cl_uuid == NULL) {
        dprintf(cl->fd, "44\n%s\n", pt->arg1);
        return;
    }
    save_message(mys, cl, pt);
    server_event_private_message_sended(cl->cl_uuid, pt->arg1, pt->arg2);
    if (searched_user.is_logged_in == 0)
        return;
    dprintf(searched_user.fd, "5\n%s\n%s\n", cl->cl_uuid, pt->arg2);
}

void messages(myserver_t *mys, client_t *cl, packet_t *pt)
{
    client_t searched_user = retrieve_saved_user(mys, NULL, pt->arg1);
    char *msg_body = (searched_user.cl_uuid != NULL) ? 
        get_ptr_to_conversations(mys, cl, pt) : NULL;

    if (searched_user.cl_uuid == NULL) {
        dprintf(cl->fd, "44\n%s\n", pt->arg1);
        return;
    }
    if (msg_body == NULL)
        return;
    write(cl->fd, msg_body, strlen(msg_body));
    free(msg_body);
}

void subscribe(myserver_t *mys, client_t *cl, packet_t *pt)
{
    dprintf(cl->fd, "7\n%s\n%s\n", cl->cl_uuid, pt->arg1);
    server_event_user_subscribed(pt->arg1, cl->cl_uuid);
}

void subscribed(myserver_t *mys, client_t *cl, packet_t *pt)
{

}

void unsubscribe(myserver_t *mys, client_t *cl, packet_t *pt)
{
    dprintf(cl->fd, "9\n%s\n%s\n", cl->cl_uuid, pt->arg1);
    server_event_user_unsubscribed(pt->arg1, cl->cl_uuid);
}
