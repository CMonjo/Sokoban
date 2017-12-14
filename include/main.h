/*
** EPITECH PROJECT, 2017
** Main
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <stdarg.h>
	#include <math.h>
	#include <SFML/Graphics.h>
	#include <SFML/Window.h>
	#include <SFML/System/Vector2.h>
	#include <SFML/Audio.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <dirent.h>
	#include <time.h>
	#include <stdlib.h>
	#include <stdarg.h>
	#include <string.h>
	#include <ncurses.h>
	#include <fcntl.h>
	#include "my.h"
	#include "struct.h"
	char *open_map(char *filepath);
	int find_player(info_t *info);
	void find_o(info_t *info);
	int calcul_lign(info_t *info);
	void verify_map(info_t *info);
	int count_obj(info_t *info, int nb_x, int nb_o, int player);
	int victory(info_t *info);
	void modified_o_in_map(info_t *info, int pos_p, int next);
	void modified_map(info_t *info, int pos_p, int next);
	int box_blocked(info_t *info);
#endif
