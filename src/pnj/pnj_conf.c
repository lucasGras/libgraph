/*
** EPITECH PROJECT, 2018
** pnj_conf_t
** File description:
** init
*/

#include <lib_graph.h>
#include "lib_graph.h"

void			cor_talk(void *data)
{
	pnj_component_t *self = (pnj_component_t *)data;
	player_t	*player = (player_t *)self->player_ptr;
	int		range = 0;

	if (player->position.x - 200 < self->position.x
	&& player->position.x + 200 > self->position.x) {
		if (player->position.y - 100 < self->position.y
		&& player->position.y + 100 > self->position.y) {
			range = 1;
		}
	}
	if (range != 1)
		return;
	self->dialog_box.displayed = sfTrue;
	if (self->dialog_box.displayed) {
		self->dialog_box.read_text(&self->dialog_box);
	}
}

void			set_pnj_visual(pnj_component_t *pnj)
{
	pnj->sprite = sfSprite_create();
	pnj->texture = sfTexture_createFromFile(ADVENTURER_PNG, NULL);
	sfSprite_setTexture(pnj->sprite, pnj->texture, sfFalse);
	sfSprite_setPosition(pnj->sprite, pnj->position);
}

pnj_component_t		*init_pnj(char *file_path, sfRenderWindow *ptr)
{
	FILE		*fd;
	pnj_component_t	*pnj = NULL;
	sfVector2i	pos_box;

	valid_conf_file(file_path, PNJ_EXT);
	fd = fopen(file_path, "r");
	pnj = malloc(sizeof(*pnj));
	pnj->window_ptr = ptr;
	pnj->name = get_fileconf_value("name", fd);
	pnj->text = get_fileconf_value("text", fd);
	pnj->dialogbox_pos = get_fileconf_value("dialog_box_pos", fd);
	pos_box = get_vector2i_str(pnj->dialogbox_pos);
	pnj->dialog_box = create_dialog_box(pos_box.x, pos_box.y);
	pnj->position = get_vector2f_str(get_fileconf_value("pnj_pos", fd));
	pnj->dialog_box.skip_button = create_button(pnj->dialog_box.button_pos,
		BUTTON_DEF, cor_skip_button, &pnj->dialog_box);
	pnj->dialog_box.tlk_text = pnj->text;
	pnj->talk = cor_talk;
	set_pnj_visual(pnj);
	return pnj;
}
