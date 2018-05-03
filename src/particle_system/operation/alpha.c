/*
** EPITECH PROJECT, 2018
** particle
** File description:
** alpha
*/

#include "lib_graph.h"

void		set_sprite_alpha(particle_t *item, int alpha)
{
	sfColor	color;

	if (item && alpha >= 0) {
		color = sfSprite_getColor(item->sprite);
		if (color.a <= 0)
			return;
		color.a = (sfUint8)alpha;
		sfSprite_setColor(item->sprite, color);
	}
}

void		cor_reset_system_rbgalpha(particle_system_t *self)
{
	int	i = 0;

	while (i < self->nb_particles) {
		self->particle_array[i].alpha_rgb = 255;
		i++;
	}
}
