/*
** EPITECH PROJECT, 2017
** Project Sokoban
** File description:
** Game end file
*/

#include "main.h"


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

void find_x(info_t *info)
{
	int i = 0;
	int j = 0;

	while (info->map[i] != '\0') {
		if (info->map[i] == 'X') {
			info->pos_x[j] = i;
			j++;
		}
		i++;
	}
	info->pos_x[j] = -1;
}

int box_blocked(info_t *info)
{
	int i = 0;

	for (i = 0; info->map[i] != '\0'; i++) {
		if (info->map[info->pos_x[i]] + 1 == '#')
			exit (1);
	}
	return (0);
}
