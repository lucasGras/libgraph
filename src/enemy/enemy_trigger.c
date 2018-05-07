/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init
*/

#include <lib_graph.h>
#include "lib_graph.h"

sfBool		axis_aligned_bounding(sfRectangleShape *rect,
	sfRectangleShape *rect2)
{
	sfFloatRect	f_rect1 = sfRectangleShape_getGlobalBounds(rect);
	sfFloatRect	f_rect2 = sfRectangleShape_getGlobalBounds(rect2);

	return sfFloatRect_intersects(&f_rect1, &f_rect2, NULL);
}

void		cor_on_trigger(enemy_t *self)
{
	sfBool	trigger = sfFalse;

	if (self->target->attack_type != NONE) {
		for (int i = 0; i < 5; i++) {
			trigger = axis_aligned_bounding(self->box_collider,
				self->target->attack_collider[i]);
		}
	}
	if (trigger == sfTrue) {
		self->life -= self->target->curent_item.damage;
		if (self->life <= 0) {
			self->target->xp += self->xp;
			self->alive = sfFalse;
		}
	}
	self->target->attack_type = NONE;
}