/*
** EPITECH PROJECT, 2018
** backpack
** File description:
** backpack
*/

#include "lib_graph.h"

void    backpack(void *animat)
{
	animator_t *self = (animator_t *)animat;

	(void)self;
}

void    face_sword(animator_t *self)
{
	int stock = self->rect.top;
	int stock_left = self->rect.left;
	int stock_width = self->rect.width;
	int stock_height = self->rect.height;

	self->rect.width = 65;
	self->rect.height = 80;
	for (self->move_rect = 0; self->move_rect != 5; self->move_rect++) {
		self->rect.top = 445;
		self->rect.left = 65 * self->move_rect;
		sfSprite_setTextureRect(self->sprite, self->rect);
		sfSprite_setPosition(self->sprite, self->pos);
		wait_for_seconds(0.05);
	}
	self->rect.top = stock;
	self->rect.left = stock_left;
	self->rect.height = stock_height;
	self->rect.width = stock_width;
	sfSprite_setTextureRect(self->sprite, self->rect);
	sfSprite_setPosition(self->sprite, self->pos);
}

void    face_sword_down(animator_t *self)
{
	int stock = self->rect.top;
	int stock_left = self->rect.left;
	int stock_width = self->rect.width;
	int stock_height = self->rect.height;

	self->rect.width = 65;
	self->rect.height = 90;
	for (self->move_rect = 0; self->move_rect != 5; self->move_rect++) {
		self->rect.top = 535;
		self->rect.left = 65 * self->move_rect;
		sfSprite_setTextureRect(self->sprite, self->rect);
		sfSprite_setPosition(self->sprite, self->pos);
		wait_for_seconds(0.05);
	}
	self->rect.top = stock;
	self->rect.left = stock_left;
	self->rect.height = stock_height;
	self->rect.width = stock_width;
	sfSprite_setTextureRect(self->sprite, self->rect);
	sfSprite_setPosition(self->sprite, self->pos);
}

void    face_sword_up(animator_t *self)
{
	int stock = self->rect.top;
	int stock_left = self->rect.left;
	int stock_width = self->rect.width;
	int stock_height = self->rect.height;
	
	self->rect.width = 65;
	self->rect.height = 90;
	for (self->move_rect = 0; self->move_rect != 5; self->move_rect++) {
		self->rect.top = 340;
		self->rect.left = 65 * self->move_rect;
		sfSprite_setTextureRect(self->sprite, self->rect);
		sfSprite_setPosition(self->sprite, self->pos);
		wait_for_seconds(0.05);
	}
	self->rect.top = stock;
	self->rect.left = stock_left;
	self->rect.height = stock_height;
	self->rect.width = stock_width;
	sfSprite_setTextureRect(self->sprite, self->rect);
	sfSprite_setPosition(self->sprite, self->pos);
}

void	atk_sword(void *animat)
{
	animator_t *self = (animator_t *)animat;
	int stock = self->rect.top;
	int stock_left = self->rect.left;
	int stock_width = self->rect.width; int stock_height = self->rect.height;

	self->rect.width = 65;
	self->rect.height = 100;
	for (self->move_rect = 0; self->move_rect != 7; self->move_rect++) {
		self->rect.top = 215;
		self->rect.left = 65 * self->move_rect;
		sfSprite_setTextureRect(self->sprite, self->rect);
		sfSprite_setPosition(self->sprite, self->pos);
		wait_for_seconds(0.05);
	}
	self->rect.top = stock;
	self->rect.left = stock_left;
	self->rect.height = stock_height;
	self->rect.width = stock_width;
	sfSprite_setTextureRect(self->sprite, self->rect);
	sfSprite_setPosition(self->sprite, self->pos);
}
