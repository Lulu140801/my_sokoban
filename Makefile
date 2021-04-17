##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## bsq
##

CC 	= 	gcc

SRC 	=		src/main.c\
				src/tiret_h.c\
				src/move.c\
				lib/my_strlen.c\
				lib/my_putstr.c\
				lib/my_strcpy.c


OBJ     = 		$(SRC:.c=.o)

NAME	=		 my_sokoban

CFLAGS 	=	-W -Wall -Wextra -pedantic


all:	$(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ) -lncurses
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all