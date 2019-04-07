##
## EPITECH PROJECT, 2018
## makefile
## File description:
## libmy makefile
##

SRC	=	src/main.c	\
		src/bsq.c	\
		src/checks.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include/

NAME	=	bsq

$(NAME):	$(OBJ)
	gcc $(OBJ) $(CFLAGS) -o $(NAME) -g

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
