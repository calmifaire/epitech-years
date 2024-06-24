##
## EPITECH PROJECT, 2020
## makefile
## File description:
## 
##

SRC	=	z.c

OBJ	=	$(SRC:.c=.o)

NAME	=	z

all:	$(NAME)

$(NAME):    $(OBJ)
	gcc -o $(NAME) $(OBJ) -std=gnu17 -Wall -Wextra

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
