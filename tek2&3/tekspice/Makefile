##
## EPITECH PROJECT, 2022
## makefile
## File description:
## Make
##

SRC	=	create.cpp \
		Circuit.cpp \
		./Src_Component/Input.cpp \
		./Src_Component/Output.cpp \
		./Src_Component/True.cpp \
		./Src_Component/False.cpp \
		./Src_Component/Clock.cpp \
		./Src_Component/4069.cpp \
		Parser.cpp \
		main.cpp \

OBJ	=	$(SRC:.cpp=.o)

NAME	=	nanotekspice

all:	$(NAME)

$(NAME):    $(OBJ)
	g++ -o $(NAME) $(OBJ) -std=c++20 -Wall -Wextra -Werror

clean:
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	rm -f $(NAME)

re:	fclean all
