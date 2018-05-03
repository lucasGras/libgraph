/*
** EPITECH PROJECT, 2018
** cor
** File description:
** button
*/

#include "lib_graph.h"

void	cor_set_scale(button_t *self, int x, int y)
{
	sfVector2f	scale = {(float)x, (float)y};

	if (!self || scale.x <= 0 || scale.y <= 0)
		return;
	sfRectangleShape_setScale(self->shape, scale);
}

void	cor_set_texture(button_t *self, char *path)
{
	if (str_is_null_or_empty(path) < 0 || !self)
		return;
	if (self->txtr)
		sfTexture_destroy(self->txtr);
	self->txtr = sfTexture_createFromFile(path, NULL);
	sfRectangleShape_setTexture(self->shape, self->txtr, sfFalse);
}
