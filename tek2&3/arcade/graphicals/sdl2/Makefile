##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	sources/ArcadeSdl2.cpp	\
		sources/CorrespSdl2.cpp	\
		sources/RawTextureSdl2.cpp

CPPFLAGS = -Wall -Wextra -fpic -I../../interfaces -I/usr/local/include/SDL2 -D_REENTRANT

OBJ = 	$(SRC:.cpp=.o)

NAME = arcade_sdl2.so

all:	$(NAME)

$(NAME):	$(OBJ)
		mkdir -p ../../lib
		g++ -shared -o $(NAME) $(OBJ) -lSDL2 -lSDL2_image -lSDL2_ttf
		mv $(NAME) ../../lib

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f ../../lib/$(NAME)

re:	fclean all
