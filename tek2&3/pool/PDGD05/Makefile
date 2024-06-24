##
## EPITECH PROJECT, 2022
## make
## File description:
## make
##

SRC	=	init_and_destroy.c \
		assign_s_and_c.c \
		append_s_and_c.c \
		at.c \
		clear_string.c \
		length.c \
		compare_s_and_c.c \
		copy.c \
		c_str.c \
		empty.c \
		find.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	libstring.a

all:	$(NAME)

$(NAME):    $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
