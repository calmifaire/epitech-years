##
## EPITECH PROJECT, 2022
## myteams [WSL: Ubuntu]
## File description:
## Makefile
##

CC = gcc

CFLAGS = -Wall

LIBFLAGS = -L./libs/myteams -lmyteams -luuid

SRC_CLI = client/main.c \
		client/loop.c \
		client/utiliti.c \
		client/check_argument.c \
		client/command_precise.c \
		client/create_argument.c \
		client/create_code.c \
		client/code_receive.c \
		client/find_argument.c \
		client/call_writting_lib.c \
		client/call_writting_lib2.c \
		client/list_argument.c \
		client/call_error.c

OBJ_CLI = $(SRC_CLI:.c=.o)

NAME_CLI = myteams_cli

SRC_SERVER = server/main.c	\
			server/server.c	\
			server/utils.c	\
			server/utils2.c	\
			server/utils3.c	\
			server/funcs.c	\
			server/funcs2.c	\
			server/funcs3.c	\
			server/save.c	\
			server/retrieve_users.c	\
			server/retrieve_users2.c	\
			server/manage_args.c	\
			server/messages.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)

NAME_SERVER = myteams_server

all: $(NAME_CLI) $(NAME_SERVER)

$(NAME_CLI): $(OBJ_CLI)
	gcc -o $(NAME_CLI) $(OBJ_CLI) $(CFLAGS) $(LIBFLAGS)

$(NAME_SERVER): $(OBJ_SERVER)
	gcc -o $(NAME_SERVER) $(OBJ_SERVER) $(CFLAGS) $(LIBFLAGS)

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLI)

fclean: clean
	rm -f $(NAME_CLI) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
