/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <sys/select.h>
    #include <netinet/tcp.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <uuid/uuid.h>
    #include <arpa/inet.h>
    #include <ctype.h>
    #include <pthread.h>
    #include <semaphore.h>
    #include <stdbool.h>
    #include <string.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <stddef.h>

    typedef struct player_s {
        int id;
        float x;
        float y;
        int score;
    }player_t;

    typedef struct coin_s coin_t;
    struct coin_s {
        sfRectangleShape *object;
        int x;
        int y;
        int map_x;
        int map_y;
        sfVector2f pos;
        sfColor color;
        coin_t *next;
    };

    typedef struct coin_list_s coin_list_t;
    struct coin_list_s {
        coin_t *first;
    };

    typedef struct client_s {
        int fd;
        char *ip;
        char *port;
        struct sockaddr_in server;
        sem_t semaphore_graphic;
        pthread_t network;
        pthread_t graphic;
        pthread_mutex_t mutex;
        char *command;
        char *receive;
        int id;
        int width;
        int height;
        bool ready;
        bool start;
        bool finish;
        char *cells;
        char **map;
        player_t *player1;
        player_t *player2;
        coin_list_t *coin_list;
    }client_t;

    typedef struct wall_s wall_t;
    struct wall_s {
        sfRectangleShape *object;
        int x;
        int y;
        sfVector2f pos;
        sfColor color;
        wall_t *next;
    };

    typedef struct wall_list_s wall_list_t;
    struct wall_list_s {
        wall_t *first;
    };

    typedef struct graphic_s {
        sfVideoMode* mode;
        sfRenderWindow* window;
        sfEvent event;
        sfRectangleShape *player1;
        sfText *score;
        sfText *cptr;
        sfFont *font;
        sfVector2f position_score;
        sfVector2f position_cptr;
        sfVector2f player1_pos;
        sfRectangleShape *player2;
        sfVector2f player2_pos;
        sfVector2f size;
        wall_list_t *wall_list;
        int ok;
    }graphic_t;

    char *trimwhitespace(char *str);
    void init_text(graphic_t *game, client_t *client);
    bool init_string_struct(client_t *client);
    int check_ret(client_t *client, fd_set *rfds, int ret);
    int get_height(client_t *client);
    void *set_up(client_t *client);
    void *graphic(client_t *client);
    int my_int_len(int nb);
    char *my_itoa(int nbr);
    char *next_word(char *str);
    void free_all(client_t *client, int code);
    void init_map(client_t *client);
    void init_thread_network_and_graphic(client_t *client);
    void join_network(client_t *client);
    void join_graphic(client_t *client);
    void loading(client_t *client);
    wall_list_t *init_list(client_t *client);
    void check_game(client_t *client);
    coin_list_t *init_list_coin(client_t *client);
    void draw_coin(client_t *client, graphic_t *game);
    void draw_wall(graphic_t *game);
    void update_move(graphic_t *game, client_t *client);
    void draw_all(graphic_t *game, client_t *client);
    void update_game(graphic_t *game, client_t *client);
    void check_keypress(graphic_t *game, client_t *client);
    void check_keyrelease(graphic_t *game, client_t *client);
    void free_game(graphic_t *game, client_t *client);
    void free_wall_list(graphic_t *game);
    void free_coin_list(client_t *client);

#endif /* !CLIENT_H_ */
