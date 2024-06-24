##
## EPITECH PROJECT, 2022
## B-PDG-300-STG-3-1-PDGRUSH3-kevin.zilliox
## File description:
## Makefile
##

SRC		=		main.cpp	\
				core/core.cpp	\
				graphic/Graphic.cpp	\
				graphic/print_info/print_User.cpp	\
				graphic/print_info/print_Os.cpp	\
				graphic/print_info/print_Ram.cpp	\
				graphic/print_info/print_Time.cpp	\
				modules/name.cpp	\
				modules/ram.cpp	\
				modules/system.cpp	\
				modules/time.cpp	\

NAME	=		MyGKrellm

OBJ 	=		$(SRC:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
		g++ -o $(NAME) -g $(OBJ) -lncurses -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f $(OBJ)
	rm -f vgcore.*

fclean:    clean
	rm -f $(NAME)

re:    fclean all