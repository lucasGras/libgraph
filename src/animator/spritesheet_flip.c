/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** flip
*/

#include "lib_graph.h"

void	flip_right(animator_t *self)
{
	sfVector2f	scale = {-1, 1};
	player_t	*player_ptr = (player_t *)self->player;

	player_ptr->horizontal_dir = 1;
	sfSprite_setScale(self->sprite, scale);
}

void	flip_left(animator_t *self)
{
	sfVector2f	scale = {1, 1};
	player_t	*player_ptr = (player_t *)self->player;

	player_ptr->horizontal_dir = -1;
	sfSprite_setScale(self->sprite, scale);
}