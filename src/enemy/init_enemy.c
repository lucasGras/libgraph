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
}

enemy_t		*create_enemy(char *path, player_t *m_target)
{
	enemy_t	*enemy = malloc(sizeof(enemy_t));
	FILE	*fd;

	valid_conf_file(path, ENEMY_EXT);
	fd = fopen(path, "r");
	enemy->name = get_fileconf_value("name", fd);
	enemy->life = my_getnbr(get_fileconf_value("life", fd));
	enemy->xp = my_getnbr(get_fileconf_value("xp", fd));
	enemy->speed = my_getnbr(get_fileconf_value("speed", fd));
	enemy->target = m_target;
	enemy->box_collider = sfRectangleShape_create();
	sfRectangleShape_setOutlineThickness(enemy->box_collider, 2);
	sfRectangleShape_setOutlineColor(enemy->box_collider, sfGreen);
	enemy->alive = sfTrue;
	enemy->thread = NULL;
	set_function(enemy);
	fclose(fd);
	return enemy;
}