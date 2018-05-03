/*
** EPITECH PROJECT, 2018
** lib_graph
** File description:
** parser bool
*/

#include "lib_graph.h"

sfBool		get_bool_str(char *str)
{
	if (str && my_strcmp(str, "true") == 0)
		return sfTrue;
	else if (my_strcmp(str, "false") == 0)
		return sfFalse;
	return sfFalse;
}
