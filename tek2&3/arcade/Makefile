##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME = do_it

CORE = $(MAKE)	-s	-C	core/

GAME1 = $(MAKE)	-s	-C	games/pacman/

GAME2 = $(MAKE)	-s	-C	games/nibbler/

NCURSES = $(MAKE)	-s	-C	graphicals/ncurses/

SDL2 = $(MAKE)	-s	-C	graphicals/sdl2/

SFML = $(MAKE)	-s	-C	graphicals/sfml/

all:	core	games	graphicals

core:
		$(CORE)

games:
		$(GAME1)
		$(GAME2)

graphicals:
		$(NCURSES)
		$(SDL2)
		$(SFML)

clean:
		@$(CORE)	clean
		@$(GAME1)	clean
		@$(GAME2)	clean
		@$(NCURSES)	clean
		@$(SDL2)	clean
		@$(SFML)	clean

fclean:	clean
		@$(CORE)	fclean
		@$(GAME1)	fclean
		@$(GAME2)	fclean
		@$(NCURSES)	fclean
		@$(SDL2)	fclean
		@$(SFML)	fclean

re:	fclean all

.PHONY:	all	core	games	graphicals	objdump	clean	fclean	re