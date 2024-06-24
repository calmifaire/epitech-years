##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRCN	=	./main.c \
		./testfile.c \
		./src_nm/explore_sys.c \
		./src_nm/get_symb.c \
		./src_nm/get_symb2.c \
		./custom_strcmp.c \
		./src_nm/stock.c \
		./src_nm/rearrange.c \

SRCO	=	./main.c \
		./testfile.c \
		./src_nm/explore_sys.c \
		./src_nm/get_symb.c \
		./src_nm/get_symb2.c \
		./custom_strcmp.c \
		./src_nm/stock.c \
		./src_nm/rearrange.c \

OBJN	=	$(SRCN:.c=.o)

OBJO    =       $(SRCO:.c=.o)

NAMEN	=	my_nm

NAMEO	=	my_objdump

all:	both

both:    $(OBJN) $(OBJO)
	gcc $(OBJN) -o $(NAMEN)
	gcc $(OBJO) -o $(NAMEO)

nm:	$(OBJN)
	gcc $(OBJN) -o $(NAMEN)

objdump:     $(OBJO)
	gcc $(OBJO) -o $(NAMEO)

clean:
	rm -f $(OBJN)
	rm -f $(OBJO)
	rm -f *~

fclean: clean
	rm -f $(NAMEN)
	rm -f $(NAMEO)

re:	fclean all
