/*
** EPITECH PROJECT, 2018
** button
** File description:
** init
*/

#include "lib_graph.h"

void		create_button_map(button_t button, sfVector2f message_pos)
{
	sfText_setPosition(button.message, message_pos);
	sfText_setColor(button.message, sfWhite);
	sfText_setString(button.message, "");
	sfText_setFont(button.message, button.font);
	sfText_setCharacterSize(button.message, 30);
}

void		set_object(button_t *button, sfVector2f position,
			char *path)
{
	sfVector2u tmp;

	set_path(button, path);
	button->shape = sfRectangleShape_create();
	button->txtr = sfTexture_createFromFile(button->path_base, NULL);
	tmp = sfTexture_getSize(button->txtr);
	button->size.x = (float)tmp.x;
	button->size.y = (float)tmp.y;
	sfRectangleShape_setSize(button->shape, button->size);
	sfRectangleShape_setTexture(button->shape, button->txtr, sfFalse);
	sfRectangleShape_setPosition(button->shape, position);
}

/**
 *\fn button_t create_button(sfVector2i pos, char *path, void (*on_click)(void *), void *data_click)
 * \brief Function to create a button
 * \param pos: position of button
 * \param path: path to the button .png
 * \param on_click: function to call when clicked
 * \param data_click: argument to send to on_click (NULL if none)
 * \return button_t if no error, NULL if error detected
 */

button_t		create_button(sfVector2i pos, char *path,
			void (*on_click)(void *), void *data_click)
{
	button_t button;
	sfVector2f message_pos;
	sfVector2f position = {(float)pos.x, (float)pos.y};

	set_object(&button, position, path);
	button.pos = position;
	message_pos.x = (float)(position.x + (button.size.x / 2.5));
	message_pos.y = position.y + (button.size.y / 4);
	button.font = sfFont_createFromFile(FONT_DEF_LIB);
	button.message = sfText_create();
	create_button_map(button, message_pos);
	button.clicked = 0;
	set_function_button(&button, on_click);
	button.data_arg = data_click;
	return button;
}
