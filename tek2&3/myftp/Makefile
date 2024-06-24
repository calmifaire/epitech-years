##
## EPITECH PROJECT, 2022
## makefile
## File description:
## Make
##

SERVER	=	server.c \
		server_loop.c \
		technical.c \
		command.c \
		command_part2.c \
		data_command.c \

OBJSERVER	=	$(SERVER:.c=.o)

SERVERNAME	=	myftp

all:	compserver

compserver:	$(OBJSERVER)
	gcc -o $(SERVERNAME) $(OBJSERVER)

clean:
	rm -f $(OBJSERVER)
	rm -f *~

fclean: clean
	rm -f $(SERVERNAME)

re:	fclean all
