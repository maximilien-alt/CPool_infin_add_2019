##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	*.c	\

NAME	=	infin_add

OBJ	=	libmy.a

all	:	$(OBJ)

$(OBJ)	:
	gcc -c lib/my/$(SRC)
	ar rc $(OBJ) *.o
	gcc -o $(NAME) -g3 infin_add.c -L. -lmy -I include

clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
