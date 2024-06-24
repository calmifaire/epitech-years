##
## EPITECH PROJECT, 2022
## B-OOP-400-STG-4-1-arcade-axel.derbisz
## File description:
## Makefile
##

NAME	=	../../serverJ2T3

SRC	=	server_jp2t3.c	\
		command.c	\
		flags.c	\
		init.c	\
		map.c	\
		server.c	\
		utils.c	\
		utils_concat.c	\
		utils_map.c	\
		sender.c	\
		sender_2.c	\
		server_utils.c	\
		utils_sender.c	\
		client_handling.c

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-W -Wall -Wextra -Wshadow	-Iinclude -I./../include -g

RM	=	@rm -f

CC	=	gcc

LDFLAGS	= -lpthread -lm

COV_TMP	=	$(SRC:%.c=%.gcda) $(SRC:%.c=%.gcno)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
		$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS)

clean:
		$(RM) $(OBJ) $(OBJ_TEST) $(OBJ_MAIN)

fclean: clean
		$(RM) $(NAME) $(TEST_NAME)

re: fclean all

.PHONY : clean fclean re tests_run clean_coverage debug