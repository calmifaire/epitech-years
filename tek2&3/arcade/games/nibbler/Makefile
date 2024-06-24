##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	sources/arcadeNibbler.cpp

CPPFLAGS = -Wall -Wextra -fpic -I../../interfaces

OBJ = 	$(SRC:.cpp=.o)

NAME = arcade_nibbler.so

all:	$(NAME)

$(NAME):	$(OBJ)
		mkdir -p ../../lib
		g++ -shared -o $(NAME) $(OBJ)
		mv $(NAME) ../../lib

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f ../../lib/$(NAME)

re:	fclean all
