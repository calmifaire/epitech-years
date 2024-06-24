##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	sources/Arcade.cpp	\
		sources/ArcadeError.cpp	\
		sources/ArcadeMain.cpp	\
		sources/ArgumentChecker.cpp	\
		sources/MainMenu.cpp	\
		sources/Texture.cpp

NAME =	arcade

CPPFLAGS = -g -I./../interfaces -Wall -Wextra -ldl

OBJ = 	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CPPFLAGS)
		mv $(NAME) ../$(NAME)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -fr ../$(NAME)

re:	fclean all
