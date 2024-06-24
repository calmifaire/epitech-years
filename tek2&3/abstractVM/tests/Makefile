##
## EPITECH PROJECT, 2022
## abstract-vm bootstrap
## File description:
## Makefile
##

SRC =	../src/Parser.cpp \
		../src/Exception.cpp \
		../src/Operand.cpp \
		../src/Factory.cpp \
		unit1.cpp \

OBJ = 	$(SRC:.cpp=.o)

NAME = 	unit_tests

CPP = g++

CPPFLAGS = -g -Wall -Wextra -std=c++11

TFLAGS = --coverage -lcriterion

all: 	$(OBJ)
		$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ) $(TFLAGS)
		./unit_tests

clean:
		rm -f $(OBJ)
		rm -f src/*.gch
		rm -f *.gcda
		rm -f *.gcno
		rm -f vgcore.*

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
