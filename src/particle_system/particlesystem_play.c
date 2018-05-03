/*
** EPITECH PROJECT, 2018
** system_p
** File description:
** play
*/

#include "lib_graph.h"

void		thread_systemp(void *data)
{
	particle_system_t	*tmp = (particle_system_t *)data;

	tmp->reset_system(tmp);
	tmp->displayed = sfTrue;
	wait_for_seconds(tmp->lenght);
	sfThread_destroy(tmp->systemp_thread);
	tmp->systemp_thread = NULL;
	tmp->displayed = sfFalse;
}

void		cor_play_system(particle_system_t *self)
{
	sfThread	*thread;

	if (!self || self->systemp_thread != NULL)
		return;
	thread = sfThread_create(thread_systemp, self);
	self->systemp_thread = thread;
	sfThread_launch(thread);
}
