##
## EPITECH PROJECT, 2017
## Project sokoban
## File description:
## Build sokoban binary.
##

CC	=	gcc

CFLAGS	=	-Wextra -W -Wall -I ./include/

LIB	=	-L lib/ -lmy -lncurses

SRC	=	src/main.c		\
		src/detection.c		\
		src/game_end.c		\
		src/info_map.c		\
		src/modified_map.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my/
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)
	rm -f $(OBJ)
	make clean -C lib/my/

clean:
	rm -f $(OBJ)
	make clean -C lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my/

re: fclean all
