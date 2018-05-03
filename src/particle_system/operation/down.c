/*
** EPITECH PROJECT, 2018
** particle
** File description:
** mvt
*/

#include "lib_graph.h"

void		mouvement_down(particle_system_t *system_p)
{
	int		i = 0;
	sfVector2f	normalize;

	while (i < system_p->nb_particles)  {
		system_p->particle_array[i].alpha_speed = 40;
		normalize = unit_vector(system_p->particle_array[i],
				system_p->particle_array[i].alpha_speed);
		normalize.x = (float)-0.2;
		normalize.y = 1;
		sfSprite_move(system_p->particle_array[i].sprite,
				normalize);
		system_p->particle_array[i].position =
		sfSprite_getPosition(system_p->particle_array[i].sprite);
		i++;
	}
}
