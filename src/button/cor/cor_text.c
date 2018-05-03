/*
** EPITECH PROJECT, 2018
** cor
** File description:
** button
*/

#include "lib_graph.h"

void	cor_set_textsize(button_t *self, float size)
{
	if (!self || size <= 0)
		return;
	sfText_setCharacterSize(self->message, size);
}

void	cor_set_textpos(button_t *self, int x, int y)
{
	sfVector2f	pos = {(float)x, (float)y};

	if (!self || pos.x < 0 || pos.y < 0)
		return;
	sfText_setPosition(self->message, pos);
}

void	cor_set_message(button_t *self, char *set)
{
	if (str_is_null_or_empty(set) < 0 || !self)
		return;
	sfText_setString(self->message, set);
}
