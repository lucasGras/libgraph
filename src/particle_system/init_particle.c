/*
** EPITECH PROJECT, 2018
** particle
** File description:
** init
*/

#include "lib_graph.h"

particle_t	init_particle(particle_system_t *system_p)
{
	particle_t	particle;

	particle.sprite = sfSprite_create();
	particle.texture = sfTexture_createFromFile(system_p->txtr_path,
								NULL);
	sfSprite_setTexture(particle.sprite, particle.texture, sfFalse);
	particle.start_pos = cor_particle_startpos(system_p);
	particle.alpha_direction = cor_particle_direction(system_p);
	particle.alpha_speed = cor_particle_speed(system_p);
	particle.alpha_rotation = cor_particle_rotation(system_p);
	particle.alpha_speed_rotation = cor_particle_Rspeed(system_p);
	particle.position = particle.start_pos;
	sfSprite_setPosition(particle.sprite, particle.start_pos);
	return particle;
}
