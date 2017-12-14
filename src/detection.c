/*
** EPITECH PROJECT, 2017
** Project Sokoban
** File description:
** Detection file
*/

#include "main.h"

char *open_map(char *filepath)
{
	int fd = open(filepath, O_RDONLY);
	char *buffer  = malloc(sizeof(char) * 1000000 + 1);
	int rd = 0;

	rd = read(fd, buffer, 1000001);
	if (rd == -1 )
		exit (84);
	close(fd);
	return (buffer);
}
