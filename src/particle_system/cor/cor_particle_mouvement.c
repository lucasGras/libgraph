/*
** EPITECH PROJECT, 2018
** particle
** File description:
** mvt
*/

#include "lib_graph.h"

void		cor_particle_mouvement(particle_system_t *system_p,
					float *global_seconds)
{
	float		seconds = get_current_seconds(system_p->mvt_clock);

	*global_seconds += *global_seconds + seconds;
	if (seconds < 0.01)
		return;
	if (system_p->type == EXPL)
		mouvement_explosion(system_p);
	else if (system_p->type == COS)
		mouvement_cosinus(system_p, *global_seconds);
	else if (system_p->type == DOWN)
		mouvement_down(system_p);
	sfClock_restart(system_p->mvt_clock);
}
