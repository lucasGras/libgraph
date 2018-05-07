/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init
*/

#include <lib_graph.h>
#include "lib_graph.h"

sfVector2f	get_target_vector(enemy_t *enemy, sfVector2f target)
{
	sfVector2f	direction;
	sfVector2f	unit;
	float		magnitude;

	direction.x = target.x - enemy->position.x;
	direction.y = target.y - enemy->position.y;
	magnitude = (float)sqrt(pow(direction.x, 2) + pow(direction.y, 2));
	unit.x = (direction.x / magnitude) * enemy->speed;
	unit.y = (direction.y / magnitude) * enemy->speed;
	return unit;
}

void		cor_active_enemy(enemy_t *self)
{
	self->thread = sfThread_create(cor_follow_target, self);
	sfThread_launch(self->thread);
}

void		cor_desactive_enemy(enemy_t *self)
{
	sfThread_destroy(self->thread);
	self->thread = NULL;
}

void		cor_mouvement(enemy_t *self, sfVector2f unit)
{
	self->position.x += unit.x;
	self->position.y += unit.y;
	sfRectangleShape_setPosition(self->box_collider, self->position);
}

void		cor_follow_target(void *data)
{
	enemy_t		*self = (enemy_t *)data;
	sfVector2f	target_follow;

	wait_for_seconds(5);
	while (self->alive) {
		target_follow = get_target_vector(self,
			self->target->position);
		self->mouvement(self, target_follow);
		self->on_trigger(self);
		wait_for_seconds(0.1);
	}
	self->desactive(self);
}