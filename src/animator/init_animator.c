/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** animator
*/

#include <lib_graph.h>
#include "lib_graph.h"

sfIntRect		create_rect(int m_width, int m_height)
{
	sfIntRect	rect;

	rect.top = 0;
	rect.left = 0;
	rect.width = m_width;
	rect.height = m_height;
	return rect;
}

static void		set_functions(animator_t *animator)
{
	animator->active = cor_animator_activate;
	animator->desactive = cor_animator_desactivate;
	animator->manage_event = cor_manage_event;
	animator->set_extern_joystick = cor_set_extern_joystick;
	animator->set_extern_keyboard = cor_set_extern_keyboard;
}

animator_t		*sub_create_animator(char *sprite_path,
				int width, int height, sfEvent *m_event)
{
	animator_t	*animator = malloc(sizeof(animator_t));

	animator->sprite_sheet_path = my_strcat_malloc(NULL, sprite_path);
	animator->sprite = sfSprite_create();
	animator->txtr = sfTexture_createFromFile(animator->sprite_sheet_path,
						NULL);
	sfSprite_setTexture(animator->sprite, animator->txtr, sfFalse);
	animator->rect = create_rect(width, height);
	animator->event = m_event;
	animator->move_rect = 0;
	animator->thread_ptr = NULL;
	animator->activate = sfFalse;
	animator->event_active = sfFalse;
	animator->d = 10;
	set_functions(animator);
	return animator;
}

animator_t		*create_animator(char *sprite_path,
				int width, int height, sfEvent *m_event)
{
	animator_t	*animator = sub_create_animator(sprite_path,
						width, height, m_event);

	animator->joystickwapper = get_joystickwrapper(animator);
	animator->keywrapper = my_keywrapper(animator);
	return animator;
}
