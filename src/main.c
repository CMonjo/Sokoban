/*
** EPITECH PROJECT, 2017
** Project Sokoban
** File description:
** Main file
*/

#include "main.h"

void detection_file(char *filepath)
{
	int detect = open(filepath, O_RDONLY);

	if (detect == -1 )
		exit (84);
}

char *open_map(char *filepath)
{
	int fd = open(filepath, O_RDONLY);
	char *buffer  = malloc(sizeof(char) * 1000000 + 1);
	int rd = 0;

	rd = read(fd, buffer, 1000001);
	close(fd);
	return (buffer);
}

int find_player(info_t *info)
{
	int i = 0;

	while (info->map[i] != 'P')
		i++;
	return (i);
}

int calcul_lign(info_t *info)
{
	int i = 0;

	while (info->map[i] != '\n')
		i++;
	return (i);
}

/*struct sokoban_t shifting_bryan(struct sokoban_t sb, int bryan, int new_statement, char keyboard)
{
	char alt = ' ';

	sb.output = keyboard;
	if (sb.map[new_statement] != '#' && sb.map[new_statement] != 'X' && sb.map[new_statement] != 'O') {
		if (sb.map[new_statement] == 'O') {
			sb.key -= 1;
		}
		alt = sb.map[new_statement];
		sb.map[new_statement] = sb.map[bryan];
		sb.map[bryan] = sb.temp;
	}
	if (sb.map[new_statement] == 'X' && sb.map[new_statement + sb.output] != '#' &&
	sb.map[new_statement + sb.output] != 'X') {
	move_block(sb, new_statement, bryan);
	}
	sb.temp = alt;
	return (sb);
}*/

void modified_map(info_t *info, int pos_p, int var)
{
	char tmp = ' ';

	if (info->map[var] != '#' && info->map[var] != 'X' && info->map[var] != 'O') {
		info->map[pos_p] = ' ';
		info->map[var] = 'P';
	}
	if (info->map[var] == 'X' && info->map[var] != '#' && info->map[var] != 'O') {
		tmp = 'X';
		info->map[pos_p] = ' ';
		info->map[var] = 'P';
		info->map[var] = tmp;
	}
}

void my_touch(info_t *info, int pos_p, int lign)
{
	switch(getch()) {
		case 'z':
			modified_map(info, pos_p, pos_p - lign);
			break;
		case 's':
			modified_map(info, pos_p, pos_p + lign);
			break;
		case 'q':
			modified_map(info, pos_p, pos_p - 1);
			break;
		case 'd':
			modified_map(info, pos_p, pos_p + 1);
			break;
		case 32:
			info->key = 0;
			break;
	}
}

void my_sokoban(char **av, info_t *info)
{
	int lign = 0;
	int pos_p = 0;
	info->key = 1;
	info->map = malloc(sizeof(char *) * 1000000 + 1);
	info->map = open_map(av[1]);
	lign = calcul_lign(info) + 1;
	initscr();
	curs_set(FALSE);
	while (info->key == 1) {
		pos_p = find_player(info);
		printw(info->map);
		noecho();
		my_touch(info, pos_p, lign);
		refresh();
		clear ();
	}
	sleep(1);
	endwin();
}

int main(int ac, char **av)
{
	info_t *info = malloc(sizeof(info_t));
	int fd = 0;
	char *buffer[1000];
	int rd = 0;

	if (ac < 2 || ac > 2)
		return (84);
	if (my_strlen(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h') {
		fd = open("info.txt", O_RDONLY);
		rd = read(fd, buffer, 185);
		write(1, buffer, rd);
	} else {
		detection_file(av[1]);
		my_sokoban(av, info);
	}
	return (0);
}
