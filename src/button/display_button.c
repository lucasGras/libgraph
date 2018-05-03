/*
** EPITECH PROJECT, 2018
** display
** File description:
** button
*/

#include "lib_graph.h"

void		cor_mouse_move(button_t *item, sfMouseMoveEvent mouse)
{
	sfVector2f	tmp;

	tmp.x = (float)mouse.x;
	tmp.y = (float)mouse.y;
	if (item->clicked == 1)
		return;
	if (item->is_hovered(item, tmp) == sfTrue)
		item->set_texture(item, item->path_hover);
	else
		item->set_texture(item, item->path_base);
}

void		cor_mouse_click(button_t *item, sfMouseButtonEvent click)
{
	sfVector2f	tmp;

	tmp.x = (float)click.x;
	tmp.y = (float)click.y;
	if (item->is_hovered(item, tmp) == sfTrue) {
		item->set_texture(item, item->path_click);
		item->clicked = 1;
		item->on_click(item->data_arg);
	} else
		item->set_texture(item, item->path_base);
}

void		active_button_action(button_t *item, sfEvent event)
{
	if (event.type == sfEvtMouseButtonPressed) {
		cor_mouse_click(item, event.mouseButton);
		return;
	}
	if (event.type == sfEvtMouseMoved) {
		cor_mouse_move(item, event.mouseMove);
		return;
	}
	item->clicked = 0;
}

void		display_button(button_t *item, sfRenderWindow *window)
{
	if (!item || !window)
		return;
	sfRenderWindow_drawRectangleShape(window, item->shape, NULL);
	sfRenderWindow_drawText(window, item->message, NULL);
}
