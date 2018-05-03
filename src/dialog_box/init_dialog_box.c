/*
** EPITECH PROJECT, 2018
** init
** File description:
** dialog
*/

#include "lib_graph.h"

void		set_component_txt(dialog_box_t *item, sfVector2f pos)
{
	sfText_setPosition(item->dynamic_text, pos);
	sfText_setColor(item->dynamic_text, sfWhite);
	sfText_setString(item->dynamic_text, "");
	sfText_setFont(item->dynamic_text, item->font);
	sfText_setCharacterSize(item->dynamic_text, 30);
}

void		set_component_sprt(dialog_box_t *item, sfVector2f pos)
{
	sfSprite_setTexture(item->box_sprt, item->box_txtr, sfFalse);
	sfSprite_setPosition(item->box_sprt, pos);
	item->displayed = sfFalse;
}

void		set_dialog_button(dialog_box_t *item, sfVector2f self_pos)
{
	sfVector2u	size = sfTexture_getSize(item->box_txtr);
	sfVector2i	pos = {(int)(self_pos.x + (size.x / 2)),
		(int)(self_pos.y + size.y)};

	item->skip = sfFalse;
	item->button_pos.x = pos.x;
	item->button_pos.y = pos.y;
}

dialog_box_t		create_dialog_box(int x, int y)
{
	dialog_box_t	item;
	sfVector2f	pos = {(float)x, (float)y};

	item.dynamic_text = sfText_create();
	item.font = sfFont_createFromFile(FONT_DEF_LIB);
	set_component_txt(&item, pos);
	item.box_sprt = sfSprite_create();
	item.box_txtr = sfTexture_createFromFile(DIALOG_BOX_TXTR, NULL);
	set_component_sprt(&item, pos);
	item.sound_buffer = sfSoundBuffer_createFromFile(DB_SOUND);
	item.sound = sfSound_create();
	sfSound_setBuffer(item.sound, item.sound_buffer);
	set_function_dialog_box(&item);
	item.thread_tmp = NULL;
	set_dialog_button(&item, pos);
	return (item);
}
