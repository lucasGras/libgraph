/*
** EPITECH PROJECT, 2018
** function pointer
** File description:
** button
*/

#include "lib_graph.h"

int	str_is_null_or_empty(char *str)
{
	if (str == NULL)
		return -1;
	if (str[0] == '\0')
		return -1;
	return 1;
}

void	set_function_button(button_t *button, void (*cor_on_click)(void *))
{
	button->set_message = cor_set_message;
	button->set_texture = cor_set_texture;
	button->set_textsize = cor_set_textsize;
	button->set_textpos = cor_set_textpos;
	button->set_scale = cor_set_scale;
	button->is_hovered = cor_is_hovered;
	button->on_click = cor_on_click;
}
