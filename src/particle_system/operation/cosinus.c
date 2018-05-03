/*
** EPITECH PROJECT, 2018
** particle
** File description:
** mvt
*/

#include "lib_graph.h"

void		mouvement_cosinus(particle_system_t *system_p,
					float global_seconds)
{
	int		i = 0;
	sfVector2f	normalize;
	rgb_t		clear_blue = create_rgb(255, 255, 255);
	rgb_t		deep_blue = create_rgb(0, 0, 153);

	while (i < system_p->nb_particles)  {
		normalize = unit_vector(system_p->particle_array[i],
				system_p->particle_array[i].alpha_speed);
		normalize.x *= cosf(global_seconds);
		normalize.y *= cosf(global_seconds);
		sfSprite_move(system_p->particle_array[i].sprite, normalize);
		system_p->particle_array[i].position =
		sfSprite_getPosition(system_p->particle_array[i].sprite);
		set_sprite_alpha(&system_p->particle_array[i],
			system_p->particle_array[i].alpha_rgb);
		system_p->particle_array[i].alpha_rgb -=
		(system_p->particle_array[i].alpha_rgb > 0) ? 1 : 0;
		i++;
	}
	color_over_time(system_p, clear_blue, deep_blue);
}
