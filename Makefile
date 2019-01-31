##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for my_ls
##

SRC	=	inc/my_putchar.c	\
		inc/my_putstr.c	\
		inc/my_getnbr.c	\
		inc/my_strlen.c	\
		inc/my_put_nbr.c	\
		src/create_game_board.c	\
		src/update_board.c	\
		src/get_keyboard_input.c	\
		src/engine.c	\
		src/artificial_intelligence.c	\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
