##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	sources/ArcadeSfml.cpp	\
		sources/CorrespSfml.cpp	\
		sources/RawTextureSfml.cpp

CPPFLAGS = -Wall -Wextra -fpic -I../../interfaces

OBJ = 	$(SRC:.cpp=.o)

NAME = arcade_sfml.so

all:	$(NAME)

$(NAME):	$(OBJ)
		mkdir -p ../../lib
		g++ -shared -o $(NAME) $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system
		mv $(NAME) ../../lib

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f ../../lib/$(NAME)

re:	fclean all
