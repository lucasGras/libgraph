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
	sfBool	trigger = axis_aligned_bounding(self->box_collider,
				self->target->attack_collider);

	if (trigger == sfTrue) {
		my_putstr("HIT !\n");
		self->alive = sfFalse;
	}
}