/*
** EPITECH PROJECT, 2018
** particle
** File description:
** display
*/

#include "lib_graph.h"

void		display_particle_system(particle_system_t system_p)
{
	int	i = 0;
	static	float	global_seconds = 0;

	if (system_p.displayed == sfFalse) {
		global_seconds = 0;
		return;
	}
	while (i < system_p.nb_particles) {
		sfRenderWindow_drawSprite(system_p.ptr,
			system_p.particle_array[i].sprite, NULL);
		cor_particle_mouvement(&system_p, &global_seconds);
		i++;
	}
}
