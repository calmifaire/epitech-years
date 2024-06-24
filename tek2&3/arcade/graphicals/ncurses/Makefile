##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	sources/ArcadeNcurses.cpp	\
		sources/CorrespNcurses.cpp	\
		sources/RawTextureNcurses.cpp

CPPFLAGS = -g -Wall -Wextra -fpic -I../../interfaces

OBJ = 	$(SRC:.cpp=.o)

NAME = arcade_ncurses.so

all:	$(NAME)

$(NAME):	$(OBJ)
		mkdir -p ../../lib
		g++ -shared -o $(NAME) $(OBJ) -lncurses
		mv $(NAME) ../../lib/

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f ../../lib/$(NAME)

re:	fclean all
