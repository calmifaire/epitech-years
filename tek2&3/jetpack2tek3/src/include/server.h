/*
** EPITECH PROJECT, 2022
** B-SYN-400-STG-4-1-jetpack2tek3-kevin.zilliox
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <sys/wait.h>
    #include <sys/time.h>
    #include <signal.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <signal.h>
    #include <sys/types.h>

    struct global_s;

    typedef struct client_s {
        int fd;
        int ID;
        bool player_is_ready;
        float player_pos_x;
        float player_pos_y;
        int fire;
        int score;
        bool game_start;
        struct global_s *core;
        struct client_s *next;
        struct client_s *prev;
    } client_t;

    typedef struct server_s {
        int server_fd;
        struct sockaddr_in in;
        struct global_s *core;
        fd_set read_group;
        fd_set write_group;
        fd_set except_group;
    } server_t;

    typedef struct global_s {
        server_t *server;
        client_t *clients;
        char **map_array;
        int port;
        char *map;
        int width_map;
        int height_map;
        int gravity;
        int is_game_started;
    } core_t;

    //Init
    core_t *init_core(char *values);
    void init_socket(server_t *server);
    client_t *init_clients();
    server_t *init_server(core_t *core);
    //Utils
    char *my_itoa(int nbr);
    int my_int_len(int nb);
    char *my_revstr(char *str);
    void free_core(core_t *core);
    void free_server(core_t *core);
    char *my_strcat2(char *str1, char *str2, int freeable);
    int list_size(client_t *client);
    char *concat_param_player1_last(char *positions, client_t **temp);
    char *concat_param_player2_last(char *positions, client_t **temp);
    char *concat_param_player2(char *positions, client_t **temp);
    char *concat_param_player1(char *positions, client_t **temp);
    int check_if_map_is_valid(char *map);
    void free_list(client_t *client);
    int check_line(char c, char *str, int *counter);
    int calc_height_map(char *map);
    int calc_width_map(char *map);
    //Flags
    char *get_port_from_flag(char *str);
    char *get_gravity_from_flag(char *str);
    char *get_map_from_flags(char *str);
    char *fill_str(char *str);
    char *check_flags(char **av);
    //Map
    char *open_map(char *filepath);
    int check_map(core_t *core);
    int check_if_map_is_valid(char *map);
    int calc_height_map(char *map);
    int calc_width_map(char *map);
    int check_line(char c, char *str, int *counter);
    char *format_map(char *map);
    //Commands
    void which_command(char *str, client_t **client);
    //Clients_handling
    void read_client(client_t **client);
    void add_client_to_list(client_t **new_client,
    int socket, int id, core_t *core);
    void accept_client(core_t *core, int id);
    void handle_clients(core_t *core);
    //Server
    void start_serveur(core_t *core);
    void update_fd_sets(core_t *core);
    void game(client_t **clients);
    void start_game(client_t **list);
    void update(client_t **list);
    void send_coin_player2(client_t *temp, int x, int y);
    void send_coin(client_t *temp, int x, int y);
    void send_pos_player2(client_t *temp, core_t *core);
    void send_pos_player1(client_t *temp);
    void send_start(client_t *temp, core_t *core);
    void send_finish_end_of_map(client_t *temp, core_t *core);
    void send_finish_player1_win(client_t *temp, core_t *core);
    void send_finish_player2_win(client_t *temp, core_t *core);
    void send_finish_no_win(client_t *temp, core_t *core);
    void concat_win_no_p(client_t *temp);
    void send_finish_end_of_map(client_t *temp, core_t *core);
    void concat_win_coin_p2(client_t *temp);
    void concat_win_coin_p1(client_t *temp);
    void start_serveur(core_t *core);
    void check_case_p2(int y, int x, core_t *core, client_t *temp);
    void handling_client_read_and_write(core_t *core, client_t *temp, clock_t *time);
    void check_case(int y, int x, core_t *core, client_t *temp);
    void check_collision_coin_p2(client_t *temp, core_t *core);
    void check_collision_coin_p1(client_t *temp, core_t *core);
    void check_case(int y, int x, core_t *core, client_t *temp);
    bool check_float(float nbr);
    void concat_win_no_p(client_t *temp);
    void check_read_from_client(core_t *core, client_t *temp);


#endif /* !SERVER_H_ */
