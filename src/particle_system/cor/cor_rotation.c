/*
** EPITECH PROJECT, 2018
** particle
** File description:
** rotation
*/

#include "lib_graph.h"

float		cor_particle_Rspeed(particle_system_t *system_p)
{
	float	speedR;

	speedR = get_random_float_range(0, system_p->max_rotation_speed);
	return speedR;
}

int		cor_particle_rotation(particle_system_t *system_p)
{
	int	rotation;

	(void)system_p;
	rotation = (get_random_int_range(0, 2) == 1) ? -1 : 1;
	return rotation;
}
