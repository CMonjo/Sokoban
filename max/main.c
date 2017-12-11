/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** .c
*/
#include <ncurses.h>
#include <stdlib.h>

int my_verif(char **av);

int my_strlen(char *str)
{
	int i = 0;

	while(str[i] != '\0')
		i++;
	return (i);
}

int main(int ac, char **av)
{
	int i = 0;
	int a = 0;
	int c = 0;

	if (ac != 2)
		return (84);
	WINDOW *container;
	initscr();
	while (c == 0) {
		curs_set(0);
		clear();
		container = subwin(stdscr, 30, 60, LINES/2 - 15, COLS/2 - 30);
		move(LINES/2 + i, COLS/2 + a);
		my_verif(av);
		box(container, ACS_VLINE, ACS_HLINE);
		refresh();
		noecho();
		switch (getch()) {
		case 115 :
			i = i >= 13 ? i = 13 : i + 1;
			break;
		case 119 :
			i = i <= -14 ? -14 : i - 1;
			break;
		case 100 :
			a = a + my_strlen(av[1]) > 27 ? 29 - my_strlen(av[1]) : a + 1;
			break;
		case 97 :
			a = a <= -29 ? -29 : a - 1;
			break;
		case 32:
			c = 1;
			break;
		}
	}
	refresh();
	endwin();
	free(container);
	return 0;
}
