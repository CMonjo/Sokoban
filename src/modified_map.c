/*
** EPITECH PROJECT, 2017
** Project Sokoban
** File description:
** Modified map file
*/

#include "main.h"

void modified_o_in_map(info_t *info, int pos_p, int next)
{
	int j = 0;

	if (info->map[next] == 'X' && info->map[next + (next - pos_p)]
	== 'O' && info->map[next] != '#') {
		info->map[pos_p] = ' ';
		info->map[next] = 'P';
		info->map[next + (next - pos_p)] = 'X';
	}
	for (; info->pos_o[j] != -1; j++) {
		if (info->map[info->pos_o[j]] == ' ')
			info->map[info->pos_o[j]] = 'O';
	}
}

void modified_map(info_t *info, int pos_p, int next)
{
	if (info->map[next] == 'O') {
		info->map[pos_p] = ' ';
		info->map[next] = 'P';
	}
	if (info->map[next] != '#' && info->map[next] != 'X' &&
	info->map[next] != 'O') {
		info->map[pos_p] = ' ';
		info->map[next] = 'P';
	}
	if (info->map[next] == 'X' && info->map[next + (next - pos_p)]
	== ' ' && info->map[next] != '#') {
		info->map[pos_p] = ' ';
		info->map[next] = 'P';
		info->map[next + (next - pos_p)] = 'X';
	}
	modified_o_in_map(info, pos_p, next);
}
