/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** anim
*/

#include <SFML/Window.h>
#include <lib_graph.h>
#include "lib_graph.h"

void	my_right(void *animat)
{
	animator_t *self = (animator_t *)animat;

	self->pos.x += self->d;
	self->rect.width = 44;
	self->rect.height = 60;
	flip_right(self);
	self->rect.top = 64;
	self->rect.left = 54 * self->move_rect;
	sfSprite_setTextureRect(self->sprite, self->rect);
	sfSprite_setPosition(self->sprite, self->pos);
}

void	my_down(void *animat)
{
	animator_t *self = (animator_t *)animat;

	self->rect.width = 44;
	self->rect.height = 70;
	self->pos.y += self->d;
	self->rect.top = 124;
	self->rect.left = 56 * self->move_rect;
	sfSprite_setTextureRect(self->sprite, self->rect);
	sfSprite_setPosition(self->sprite, self->pos);
}

void	my_up(void *animat)
{
	animator_t *self = (animator_t *)animat;

	self->rect.width = 44;
	self->rect.height = 60;
	self->pos.y -= self->d;
	self->rect.top = 0;
	self->rect.left = 56 * self->move_rect;
	sfSprite_setTextureRect(self->sprite, self->rect);
	sfSprite_setPosition(self->sprite, self->pos);
}

void	my_left(void *animat)
{
	animator_t *self = (animator_t *)animat;

	self->rect.width = 44;
	self->rect.height = 60;
	self->pos.x -= self->d;
	flip_left(self);
	self->rect.top = 64;
	self->rect.left = 56 * self->move_rect;
	sfSprite_setTextureRect(self->sprite, self->rect);
	sfSprite_setPosition(self->sprite, self->pos);
}

void	spritesheet_mouvement(animator_t *self)
{
	int	i = 0;

	if (self->move_rect >= 5)
		self->move_rect = 0;
	while (self->keywrapper[i].call) {
		if (sfKeyboard_isKeyPressed(self->keywrapper[i].key)) {
		 	self->stack_function = i;
		 	//self->keywrapper[i].call(self->keywrapper[i].argument);
		}
		i++;
	}
	self->move_rect++;
	wait_for_seconds(0.01);
}
