##
## EPITECH PROJECT, 2022
## makefile
## File description:
## Make
##

SRC	=	main.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	my_convert_temp

all:	$(NAME)

$(NAME):    $(OBJ)
	g++ -o $(NAME) $(OBJ) -std=c++20 -Wall -Wextra -Werror

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
