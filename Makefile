##
## EPITECH PROJECT, 2017
## Project sokoban
## File description:
## Build sokoban binary.
##

CC	=	gcc

CFLAGS	=	-Wextra -W -Wall -Werror -I ./include/

LIB	=	-L lib/ -lmy -lncurses

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my/
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
