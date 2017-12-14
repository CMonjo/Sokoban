/*
** EPITECH PROJECT, 2017
** Project Sokoban
** File description:
** Main file
*/

#include "main.h"

int count_obj(int nb_x, int nb_o, int player)
{
	if (nb_x != nb_o || nb_o != nb_x || player != 1)
		exit (84);
	return (0);
}

void verify_map(info_t *info)
{
	int i = 0;
	int nb_x = 0;
	int nb_o = 0;
	int player = 0;

	while (info->map[i] != '\0') {
		switch(info->map[i]) {
			case 'P':
				player++;
				break;
			case 'X':
				nb_x++;
				break;
			case 'O':
				nb_o++;
				break;
		}
		i++;
	}
	count_obj(nb_x, nb_o, player);
}

int victory(info_t *info)
{
	int i = 0;

	while (info->pos_o[i] != -1) {
		if (info->map[info->pos_o[i]] == 'X')
			i++;
		else
			return (0);
	}
	info->key = 0;
	return (0);
}

int find_player(info_t *info)
{
	int i = 0;

	while (info->map[i] != 'P')
		i++;
	return (i);
}

void find_o(info_t *info)
{
	int i = 0;
	int j = 0;

	while (info->map[i] != '\0') {
		if (info->map[i] == 'O') {
			info->pos_o[j] = i;
			j++;
		}
		i++;
	}
	info->pos_o[j] = -1;
}

int calcul_lign(info_t *info)
{
	int i = 0;

	while (info->map[i] != '\n')
		i++;
	return (i);
}

void modified_map(info_t *info, int pos_p, int next)
{
	int j = 0;

	if (info->map[next] == 'O') {
		info->map[pos_p] = ' ';
		info->map[next] = 'P';
	}
	if (info->map[next] != '#' && info->map[next] != 'X' && info->map[next] != 'O') {
		info->map[pos_p] = ' ';
		info->map[next] = 'P';
	}
	if (info->map[next] == 'X' && info->map[next + (next - pos_p)] == ' ' && info->map[next] != '#') {
		info->map[pos_p] = ' ';
		info->map[next] = 'P';
		info->map[next + (next - pos_p)] = 'X';
	}
	if (info->map[next] == 'X' && info->map[next + (next - pos_p)] == 'O' && info->map[next] != '#') {
		info->map[pos_p] = ' ';
		info->map[next] = 'P';
		info->map[next + (next - pos_p)] = 'X';
	}
	for (; info->pos_o[j] != -1; j++) {
		if (info->map[info->pos_o[j]] == ' ')
			info->map[info->pos_o[j]] = 'O';
	}
}

void my_touch(info_t *info, int pos_p, int lign, char **av)
{
	switch(getch()) {
		case KEY_UP:
			modified_map(info, pos_p, pos_p - lign);
			break;
		case KEY_DOWN:
			modified_map(info, pos_p, pos_p + lign);
			break;
		case KEY_LEFT:
			modified_map(info, pos_p, pos_p - 1);
			break;
		case KEY_RIGHT:
			modified_map(info, pos_p, pos_p + 1);
			break;
		case 32:
			info->map = open_map(av[1]);
			break;
	}
}

void init(info_t *info, char **av)
{
	info->key = 1;
	info->pos_o = malloc(sizeof(int *) * 1000);
	info->pos_x = malloc(sizeof(int *) * 1000);
	info->map = malloc(sizeof(char *) * 1000000 + 1);
	info->map = open_map(av[1]);
	verify_map(info);
}

void my_sokoban(char **av, info_t *info)
{
	int lign = 0;
	int pos_p = 0;
	lign = calcul_lign(info) + 1;
	find_o(info);
	initscr();
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	while (info->key == 1) {
		pos_p = find_player(info);
		printw(info->map);
		noecho();
		my_touch(info, pos_p, lign, av);
		victory(info);
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
		fd = open("txt/info.txt", O_RDONLY);
		rd = read(fd, buffer, 185);
		write(1, buffer, rd);
	} else {
		init(info, av);
		my_sokoban(av, info);
	}
	return (0);
}
