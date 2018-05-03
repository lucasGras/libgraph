/*
** EPITECH PROJECT, 2018
** pnj_conf_t
** File description:
** display
*/

#include "lib_graph.h"

void	display_pnj(pnj_component_t *pnj, sfBool force_display)
{
	sfRenderWindow_drawSprite(pnj->window_ptr, pnj->sprite, NULL);
	if (force_display)
		pnj->dialog_box.displayed = sfTrue;
	display_dialog_box(&pnj->dialog_box, pnj->window_ptr);
}
