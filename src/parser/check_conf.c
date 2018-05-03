/*
** EPITECH PROJECT, 2018
** db
** File description:
** func
*/

#include "lib_graph.h"

int		valid_conf_file(char *path, char *ext)
{
	int i = 0;

	if (!path)
		return -1;
	while (path && path[i]) {
		if (my_strcmp(&path[i], ext) == 0)
			return 1;
		i++;
	}
	my_putstr(path);
	my_putstr(": Invalid conf file.\n");
	return 1;
}
