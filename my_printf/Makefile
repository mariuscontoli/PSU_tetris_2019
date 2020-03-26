##
## EPITECH PROJECT, 2019
## Makefile my_printf
## File description:
## Will compile our project
##

CC	=	gcc

NAME 	=	libmy.a

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

%.o: %.c
	$(CC) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $@ $^

clean:
	rm -rf *.o

fclean:	clean
	rm -f $(NAME)

re: fclean all
