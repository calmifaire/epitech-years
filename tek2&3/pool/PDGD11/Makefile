##
## EPITECH PROJECT, 2022
## makefile
## File description:
## Make
##

TS1	=	tests/test_Encapsulation.cpp \
		ex00/Picture.cpp \
		ex00/Toy.cpp

TS2	=	tests/test_Canonical_form.cpp \
		ex01/Picture.cpp \
                ex01/Toy.cpp

OBJ	=	$(TS1:.cpp=.o)

OBJ2	=	$(TS2:.cpp=.o)

NAME1	=	unit_test1

NAME2	=	unit_test2

tests_run:	$(NAME1)

$(NAME1):    $(OBJ) $(OBJ2)
	g++ -o $(NAME1) $(OBJ) -std=c++20 -Wall -Wextra -Werror --coverage -lcriterion
	g++ -o $(NAME2) $(OBJ2) -std=c++20 -Wall -Wextra -Werror --coverage -lcriterion
	./unit_test1
	./unit_test2

clean:
	rm -f *.gc* $(OBJ) $(OBJ2)

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re:	fclean tests_run
