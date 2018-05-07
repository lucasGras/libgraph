/*
** EPITECH PROJECT, 2018
** backpack
** File description:
** backpack
*/

#include "lib_graph.h"

void	set_attack_type(animator_t *self, attack_type_t type)
{
	player_t	*player_ptr = (player_t *)self->player;

	if (type == LEFT) {
		type = (player_ptr->horizontal_dir == 1) ? RIGHT : LEFT;
	}
	player_ptr->attack_type = type;
}

void    face_sword(animator_t *self)
{
	sfIntRect	stock = self->rect;

	set_attack_type(self, LEFT);
	self->rect.width = 65;
	self->rect.height = 80;
	for (int i = 0; i <= 5; i++) {
		self->rect.top = 445;
		self->rect.left = 65 * i;
		sfSprite_setTextureRect(self->sprite, self->rect);
		sfSprite_setPosition(self->sprite, self->pos);
		wait_for_seconds(0.04);
	}
	self->rect = stock;
	sfSprite_setTextureRect(self->sprite, self->rect);
	sfSprite_setPosition(self->sprite, self->pos);
}

void    face_sword_down(animator_t *self)
{
	sfIntRect	stock = self->rect;

	set_attack_type(self, BOT);
	self->rect.width = 65;
	self->rect.height = 90;
	for (int i = 0; i <= 5; i++) {
		self->rect.top = 535;
		self->rect.left = 65 * i;
		sfSprite_setTextureRect(self->sprite, self->rect);
		sfSprite_setPosition(self->sprite, self->pos);
		wait_for_seconds(0.05);
	}
	self->rect = stock;
	sfSprite_setTextureRect(self->sprite, self->rect);
	sfSprite_setPosition(self->sprite, self->pos);
	set_attack_type(self, NONE);
}

void    face_sword_up(animator_t *self)
{
	sfIntRect	stock = self->rect;

	set_attack_type(self, TOP);
	self->rect.width = 65;
	self->rect.height = 90;
	for (int i = 0; i <= 5; i++) {
		self->rect.top = 340;
		self->rect.left = 65 * i;
		sfSprite_setTextureRect(self->sprite, self->rect);
		sfSprite_setPosition(self->sprite, self->pos);
		wait_for_seconds(0.05);
	}
	self->rect = stock;
	sfSprite_setTextureRect(self->sprite, self->rect);
	sfSprite_setPosition(self->sprite, self->pos);
}

void	atk_sword(void *animat)
{
	animator_t *self = (animator_t *)animat;
	sfIntRect	stock = self->rect;

	set_attack_type(self, AROUND);
	self->rect.width = 65;
	self->rect.height = 100;
	for (int i = 0; i <= 7; i++) {
		self->rect.top = 215;
		self->rect.left = 65 * i;
		sfSprite_setTextureRect(self->sprite, self->rect);
		wait_for_seconds(0.05);
	}
	self->rect = stock;
	sfSprite_setTextureRect(self->sprite, self->rect);
	sfSprite_setPosition(self->sprite, self->pos);
}
