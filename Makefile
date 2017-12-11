##
## EPITECH PROJECT, 2017
## Project sokoban
## File description:
## Build sokoban binary.
##

CC	=	gcc

CFLAGS	=	-Wextra -W -Wall -Werror -I ./include/

LIB	=	-lncurses

SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
