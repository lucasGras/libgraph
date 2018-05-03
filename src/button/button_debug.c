/*
** EPITECH PROJECT, 2018
** button
** File description:
** debug
*/

#include "lib_graph.h"

void		debug_mode(char *str)
{
	if (lib_graph_debug == 1) {
		my_putstr(str);
		my_putstr("\n");
	}
}
