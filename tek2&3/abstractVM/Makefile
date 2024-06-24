##
## EPITECH PROJECT, 2022
## abstract-vm bootstrap
## File description:
## Makefile
##

SRC =	src/Parser.cpp \
		src/Exception.cpp \
		src/Operand.cpp \
		src/Factory.cpp \
		src/Main.cpp \

SRCT =	src/Parser.cpp \
		src/Exception.cpp \
		src/Operand.cpp \
		src/Factory.cpp \

OBJ = 	$(SRC:.cpp=.o)

OBJT = 	$(SRCT:.cpp=.o)

NAME = 	abstractVM

NAMET = test

CPP = g++

CPPFLAGS = -g -Wall -Wextra -std=c++11

TFLAGS = --coverage -lcriterion

all: 	$(OBJ)
		$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)

tests_run:  fclean
			(cd tests; make)

clean:
		rm -f $(OBJ)
		(cd tests; make clean)
		rm -f src/*.gch
		rm -f *.gcda
		rm -f *.gcno
		rm -f vgcore.*

fclean: clean
		rm -f $(NAME)
		(cd tests; make fclean)

re: fclean all

.PHONY: all clean fclean re
