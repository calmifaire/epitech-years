/*
** EPITECH PROJECT, 2022
** myteams [WSL: Ubuntu]
** File description:
** messages
*/

#include "myteams_server.h"
#include "data.h"

void set_filename(char *handle, client_t *cl, packet_t *pt, myserver_t *mys)
{
    char *sender = cl->name;
    char *receiver = retrieve_saved_user(mys, NULL, pt->arg1).name;

    if (strcmp(sender, receiver) < 0) {
        sprintf(handle, "./save/msgs/%s_%s.txt", sender, receiver);
    } else {
        sprintf(handle, "./save/msgs/%s_%s.txt", receiver, sender);
    }
}

void save_message(myserver_t *mys, client_t *cl, packet_t *pt)
{
    time_t timestamp = time(NULL);
    char filename[200];
    int fd;

    set_filename(filename, cl, pt, mys);
    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    dprintf(fd, "%s\n%ld\n%s\n\n", cl->cl_uuid, timestamp, pt->arg2);
    close(fd);
}

char *get_ptr_to_conversations(myserver_t *mys, client_t *cl, packet_t *pt)
{
    char buffer[200];
    int fd;
    char *to_ret;
    struct stat st;

    set_filename(buffer, cl, pt, mys);
    if (stat(buffer, &st) == -1 || st.st_size == 0)
        return (NULL);
    fd = open(buffer, O_RDONLY);
    to_ret = safe_malloc(sizeof(char) * (st.st_size + 1 + 
        strlen("6\n")));
    strcpy(to_ret, "6\n");
    read(fd, to_ret + strlen("6\n"), st.st_size);
    to_ret[st.st_size + strlen("6\n") - 1] = '\0';
    close(fd);
    return (to_ret);
}
