/*
** EPITECH PROJECT, 2018
** cor
** File description:
** button
*/

#include "lib_graph.h"

sfBool	cor_is_hovered(button_t *self, sfVector2f pos)
{
	if (!self)
		return sfFalse;
	if (pos.x > self->pos.x
	&& pos.x < (self->pos.x + self->size.x)) {
		if (pos.y > self->pos.y
		&& pos.y < (self->pos.y + self->size.y))
			return sfTrue;
	}
	return sfFalse;
}
