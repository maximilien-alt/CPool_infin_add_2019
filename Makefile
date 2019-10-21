##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	*.c	\

OBJ	=	libmy.a

all	:	$(OBJ)

$(OBJ)	:
	gcc -c lib/my/$(SRC)
	ar rc $(OBJ) *.o

clean	:
	rm -f *.o

fclean	: clean
	rm -f $(OBJ)

re	: fclean all
