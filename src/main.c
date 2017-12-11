/*
** EPITECH PROJECT, =pdate=
** Project =pname=
** File description:
** Main file
*/

#include "main.h"

char *open_map(char *filepath)
{
	int fd = open(filepath, O_RDONLY);
	char *buffer[1000];
	int rd = 0;

	rd = read(fd, buffer, 1000);
	write(1, buffer, rd);
	close(fd);
	return (*buffer);
}

void my_sokoban(char **av)
{
	int y = 0;
	int x = 0;
	int key = 1;
	char *map = malloc(sizeof(char *) * 1000);

	map = open_map(av[1]);
	//printf("map = \n%s\n", map);
	initscr();
	curs_set(FALSE);
	while (key == 1) {
		mvprintw(LINES / 2 + x, COLS / 2 + y, map);
		noecho();
		switch(getch()) {
			case 'z':
				x--;
				break;
			case 's':
				x++;
				break;
			case 'q':
				y -= 3;
				break;
			case 'd':
				y += 3;
				break;
			case 32:
				key = 0;
				break;
		}
		refresh();
		clear ();
	}
	sleep(1);
	endwin();
}

int main(int ac, char **av)
{
	int fd = 0;
	char *buffer[1000];
	int rd = 0;

	if (ac < 2)
		return (84);
	if (av[1][0] == '-' && av[1][1] == 'h') {
		fd = open("info.txt", O_RDONLY);
		rd = read(fd, buffer, 185);
		write(1, buffer, rd);
	} else
		my_sokoban(av);
	return (0);
}
