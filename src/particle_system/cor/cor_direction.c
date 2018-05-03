/*
** EPITECH PROJECT, 2018
** particle
** File description:
** direction
*/

#include "lib_graph.h"

sfVector2f	unit_vector(particle_t particle, float speed)
{
	sfVector2f	direction;
	sfVector2f	unit;
	float		x = particle.alpha_direction.x;
	float		y = particle.alpha_direction.y;
	float		magnitude;

	direction.x = x - particle.start_pos.x;
	direction.y = y - particle.start_pos.y;
	magnitude = (float)sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	unit.x = (direction.x / magnitude) * speed;
	unit.y = (direction.y / magnitude) * speed;
	return unit;
}

float		cor_particle_speed(particle_system_t *system_p)
{
	float	speed;

	speed = get_random_int_range(system_p->min_speed,
					system_p->max_speed);
	return speed / 2;
}

sfVector2f	cor_particle_direction(particle_system_t *system_p)
{
	sfVector2f	direction;
	int		x = 0;
	int		y = 0;

	if (system_p->type == DOWN) {
		x = get_random_int_range((int)system_p->origin.x
		- system_p->range, (int)system_p->origin.x
		+ system_p->range);
		y = get_random_int_range((int)system_p->origin.y
		+ system_p->range, (int)system_p->origin.y
		+ system_p->range + DIRECTION_OUTRANGE);
	}
	x = get_random_int_range((int)system_p->origin.x,
	((int)system_p->origin.x + system_p->range) + DIRECTION_OUTRANGE);
	y = get_random_int_range((int)system_p->origin.y,
	((int)system_p->origin.y + system_p->range) + DIRECTION_OUTRANGE);
	direction.x = x - system_p->range;
	direction.y = y - system_p->range;
	return direction;
}
