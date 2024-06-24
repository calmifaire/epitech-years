##
## EPITECH PROJECT, 2022
## B-OOP-400-STG-4-1-arcade-axel.derbisz
## File description:
## Makefile
##

NAME	=	../../clientJ2T3

SRC	=	clientjp2t3.c \
		set_up_game.c \
		functinal.c \
		map.c \
		init_thread.c \
		init_struct.c \
		init_text.c	\
		in_game_message.c \
		game.c \
		draw_object.c \
		game_update.c \

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-W -Wall -Wextra -Wshadow	-Iinclude -I./../../include -g

LDFLAGS	=	-lpthread -lcsfml-graphics -lcsfml-window -lcsfml-system

RM	=	@rm -f

CC	=	gcc

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
		$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS)

clean:
		$(RM) $(OBJ) $(OBJ_TEST) $(OBJ_MAIN)

fclean: clean
		$(RM) $(NAME) $(TEST_NAME)

re: fclean all

.PHONY : clean fclean re tests_run clean_coverage debug