/*
** EPITECH PROJECT, 2017
** Project Sokoban
** File description:
** Info map file
*/

#include "main.h"

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

int count_obj(info_t *info, int nb_x, int nb_o, int player)
{
	int i = 0;

	while (info->map[i] != '\0') {
		if (info->map[i] == ' ' || info->map[i] == '#' ||
		info->map[i] == 'O' || info->map[i] == 'P' || info->map[i]
		== 'X' || info->map[i] == '\0' || info->map[i] == '\n')
			i++;
		else
			exit (84);
	}
	if (nb_x != nb_o || nb_o != nb_x || player != 1 ||
		nb_x == 0|| nb_o == 0)
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
	count_obj(info, nb_x, nb_o, player);
}
