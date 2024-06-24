##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	Check.hs

OBJ	=	$(SRC:.hs=.o)

HIC	=	$(SRC:.hs=.hi)

NAME	=	pushswap_checker

all:	$(NAME)

$(NAME):	$(SRC)
	ghc $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(HIC)

fclean: clean
	rm -f $(NAME)

re:	fclean all
