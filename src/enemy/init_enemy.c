/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** init
*/

#include <lib_graph.h>
#include "lib_graph.h"

void		set_function(enemy_t *enemy)
{
	enemy->on_trigger = cor_on_trigger;
	enemy->active = cor_active_enemy;
	enemy->desactive = cor_desactive_enemy;
	enemy->mouvement = cor_mouvement;
}

void		set_box_collider(enemy_t *enemy)
{
	sfVector2u	tmp = sfTexture_getSize(enemy->texture);
	sfVector2f	size = {(float)tmp.x, (float)tmp.y};

	sfRectangleShape_setOutlineThickness(enemy->box_collider, 2);
	sfRectangleShape_setOutlineColor(enemy->box_collider, sfGreen);
	sfRectangleShape_setPosition(enemy->box_collider, enemy->position);
	sfRectangleShape_setSize(enemy->box_collider, size);
	sfRectangleShape_setTexture(enemy->box_collider,
		enemy->texture, sfFalse);
}

void		set_enemy_conf(enemy_t *enemy, FILE *fd)
{
	enemy->name = get_fileconf_value("name", fd);
	enemy->life = my_getnbr(get_fileconf_value("life", fd));
	enemy->xp = my_getnbr(get_fileconf_value("xp", fd));
	enemy->speed = my_getnbr(get_fileconf_value("speed", fd));
	enemy->texture = sfTexture_createFromFile(
		get_fileconf_value("path", fd), sfFalse);
	enemy->rect = get_rect_by_vector(
		get_vector2i_str(get_fileconf_value("rect", fd)));
	enemy->max_offset = my_getnbr(get_fileconf_value("max_offset", fd));
}

enemy_t		*create_enemy(char *path, player_t *m_target,
				sfRenderWindow *ptr, sfVector2f pos)
{
	enemy_t	*enemy 	= malloc(sizeof(enemy_t));
	FILE	*fd;

	valid_conf_file(path, ENEMY_EXT);
	fd = fopen(path, "r");
	set_enemy_conf(enemy, fd);
	enemy->position = pos;
	enemy->target = m_target;
	enemy->box_collider = sfRectangleShape_create();
	set_box_collider(enemy);
	enemy->alive = sfTrue;
	enemy->thread = NULL;
	enemy->window_ptr = ptr;
	set_function(enemy);
	fclose(fd);
	return enemy;
}