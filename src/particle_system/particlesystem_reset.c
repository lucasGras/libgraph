/*
** EPITECH PROJECT, 2018
** system
** File description:
** reset
*/

#include "lib_graph.h"

void		cor_reset_system(particle_system_t *self)
{
	int	i = 0;
	int	total = self->nb_particles;

	self->displayed = sfFalse;
	while (i < total) {
		sfSprite_destroy(self->particle_array[i].sprite);
		sfTexture_destroy(self->particle_array[i].texture);
		self->particle_array[i] = init_particle(self);
		i++;
	}
	self->reset_system_rgbalpha(self);
}
