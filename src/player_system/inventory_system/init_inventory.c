/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** inventory
*/

#include <SFML/Audio.h>
#include <lib_graph.h>
#include "lib_graph.h"

void			init_current_spe(inventory_visual_t *visual)
{
	sfVector2f	pos = {SCREEN_X, SCREEN_Y};

	visual->current_spe_sprt = sfSprite_create();
	visual->current_spe_txtr = sfTexture_createFromFile(INVENTORY_SPE,
								NULL);
	sfSprite_setTexture(visual->current_spe_sprt,
		visual->current_spe_txtr, sfFalse);
	pos.x -= (float)sfTexture_getSize(visual->current_spe_txtr).x / 2;
	pos.y -= (float)sfTexture_getSize(visual->current_spe_txtr).x / 2;
	sfSprite_setPosition(visual->current_spe_sprt, pos);
}

inventory_visual_t	init_inventory_visual(void)
{
	sfVector2f		pos = {SCREEN_X / 2, SCREEN_Y / 2};
	inventory_visual_t	visual;

	visual.inventory_sprt = sfSprite_create();
	visual.inventory_txtr =
		sfTexture_createFromFile(INVENTORY_VISUAL, NULL);
	sfSprite_setTexture(visual.inventory_sprt, visual.inventory_txtr,
		sfFalse);
	pos.x -= (float)sfTexture_getSize(visual.inventory_txtr).x / 2;
	pos.y -= (float)sfTexture_getSize(visual.inventory_txtr).y / 2;
	sfSprite_setPosition(visual.inventory_sprt, pos);
	return  visual;
}