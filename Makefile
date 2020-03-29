##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME    =       tetris

SRC     =       $(shell find . -name '*.c')

OBJ     =       $(SRC:.c=.o)

CFLAGS  +=      -Wall -Wextra -Wno-unused-parameter -g3 -g

CFLAGS  +=      -I./include

all     :       $(NAME)

$(NAME) :       $(OBJ)
				gcc -o $(NAME) $(OBJ) -lncurses

clean   :
				find . -name "*.o" -type f -delete
				find . -name "vgcore.*" -type f -delete

fclean  :       clean
				rm -f $(NAME)

re      :       fclean all
				find . -name "*.o" -type f -delete