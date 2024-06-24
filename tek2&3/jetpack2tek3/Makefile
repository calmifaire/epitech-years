##
## EPITECH PROJECT, 2022
## B-OOP-400-STG-4-1-arcade-axel.derbisz
## File description:
## Makefile
##

all:
	$(MAKE) -C src/client/
	$(MAKE) -C src/server/


clean:
	@$(MAKE) -C src/client/ clean
	@$(MAKE) -C src/server/ clean

fclean: clean
	@$(MAKE) -C src/client/ fclean
	@$(MAKE) -C src/server/ fclean

re: fclean all

server:
	$(MAKE) -C src/server/

client:
	$(MAKE) -C src/client/

.PHONY : clean fclean re tests_run clean_coverage debug games graphicals core