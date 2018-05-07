/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** anim
*/

#include <lib_graph.h>
#include "lib_graph.h"

void	atk_arrow_up(animator_t *self)
{
	self->stack_function = -1;
	self->move_rect = 0;
	while (self->move_rect != 6) {
		self->rect.top = 635;
		self->rect.left = 58 * self->move_rect;
		self->move_rect++;
		sfSprite_setTextureRect(self->sprite, self->rect);
		sfSprite_setPosition(self->sprite, self->pos);
		wait_for_seconds(0.01);
	}
}

void	atk_arrow_down(animator_t *self)
{
	self->stack_function = -1;
	self->move_rect = 0;
	self->rect.width = 55;
	self->rect.height = 56;
	while (self->move_rect != 6) {
		self->rect.top = 758;
		self->rect.left = 53 * (self->move_rect + 0.2);
		self->move_rect++;
		sfSprite_setTextureRect(self->sprite, self->rect);
		sfSprite_setPosition(self->sprite, self->pos);
		wait_for_seconds(0.01);
	}
}

void	atk_arrow(animator_t *self)
{
	self->stack_function = -1;
	self->move_rect = 0;
	self->rect.width = 58;
	while (self->move_rect != 6) {
		self->rect.top = 700;
		self->rect.left = 58 * (self->move_rect - 0.1);
		self->move_rect++;
		sfSprite_setTextureRect(self->sprite, self->rect);
		sfSprite_setPosition(self->sprite, self->pos);
		wait_for_seconds(0.01);
	}
}

void	check_arrow(void *animat)
{
	animator_t *self = (animator_t *)animat;

	self->stack_function = -1;
	if (self->rect.top == 64 || self->rect.top == 700
	|| self->rect.top == 425)
		atk_arrow(self);
	else if (self->rect.top == 124 || self->rect.top == 758
	|| self->rect.top == 525)
		atk_arrow_down(self);
	else if (self->rect.top == 0 || self->rect.top == 635
	|| self->rect.top == 325)
		atk_arrow_up(self);
}

void	check_sword(void *animat)
{
	animator_t *self = (animator_t *)animat;

	if (self->stack_function == -1)
		return;
	self->stack_function = -1;
	if (self->rect.top == 64 || self->rect.top == 425
	|| self->rect.top == 700)
		face_sword(self);
	else if (self->rect.top == 124 || self->rect.top == 525
	|| self->rect.top == 758)
		face_sword_down(self);
	else if (self->rect.top == 0 || self->rect.top == 325
	|| self->rect.top == 635)
		face_sword_up(self);
}
