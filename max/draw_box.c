/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** .c
*/
#include <ncurses.h>
#include <stdlib.h>

int my_verif(char **av)
{
	int i = 0;
	int a = 0;

	while (av[1][i] != '\0') {
		if (a > 29) {
			move(LINES/2 + 1, COLS/2);
			a = 0;
		}
		printw("%c", av[1][i]);
		i++;
		a++;
	}
	return 0;
}
