/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** inventory
*/

#include <lib_graph.h>
#include "lib_graph.h"

void		display_inventory(player_t *self)
{
	if (self->inventory_displayed) {
		sfRenderWindow_drawSprite(self->window_ptr,
			self->inventory_visual.inventory_sprt, NULL);
	}
}