/*
** EPITECH PROJECT, 2018
** lib_graph
** File description:
** active animator
*/

#include <lib_graph.h>
#include "lib_graph.h"

void		animator_statement(void *data)
{
	animator_t	*animator = (animator_t *)data;
	sfVector2f	setter_pos;
	player_t	*player = (player_t *)animator->player;

	while (animator->activate) {
		setter_pos = sfSprite_getPosition(animator->sprite);
		player->position = setter_pos;
		if (animator->stack_function != -1) {
			animator->keywrapper[animator->stack_function].call(
			animator->keywrapper
			[animator->stack_function].argument);
			animator->stack_function = -1;
		}
	}
}

void		cor_animator_activate(animator_t *self, void *m_player)
{
	sfThread	*animator_thread;

	self->player = m_player;
	if (self->activate == sfFalse) {
		animator_thread = sfThread_create(animator_statement, self);
		self->activate = sfTrue;
		self->thread_ptr = animator_thread;
		sfThread_launch(animator_thread);
	}
}

void		cor_animator_desactivate(animator_t *self)
{
	if (self->activate == sfTrue) {
		self->activate = sfFalse;
		sfThread_destroy(self->thread_ptr);
		self->thread_ptr = NULL;
	}
}
