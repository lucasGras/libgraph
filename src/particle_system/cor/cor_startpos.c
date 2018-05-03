/*
** EPITECH PROJECT, 2018
** particle
** File description:
** startpos
*/

#include "lib_graph.h"

sfVector2f	cor_particle_startpos(particle_system_t *system_p)
{
	sfVector2f	startpos;
	int		x = 0;
	int		y = 0;

	if (system_p->type == EXPL)
		return system_p->origin;
	x = get_random_int_range((int)system_p->origin.x,
			(int)system_p->origin.x + system_p->range);
	y = get_random_int_range((int)system_p->origin.y,
			(int)system_p->origin.y + system_p->range);
	startpos.x = (float)(x - system_p->range);
	startpos.y = (float)(y - system_p->range);
	return startpos;
}
