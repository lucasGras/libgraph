/*
** EPITECH PROJECT, 2018
** db
** File description:
** display
*/

#include "lib_graph.h"

void		display_dialog_box(dialog_box_t *item,
				sfRenderWindow *window)
{
	if (!item || !window || item->displayed == sfFalse)
		return;
	sfRenderWindow_drawSprite(window, item->box_sprt, NULL);
	sfRenderWindow_drawText(window, item->dynamic_text, NULL);
	display_button(&item->skip_button, window);
}
