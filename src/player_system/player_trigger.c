/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** player
*/

#include <lib_graph.h>
#include "lib_graph.h"

sfVector2f	get_collider_position(player_t *player, int index)
{
	sfVector2f	pos;

	if (index == 0) {
		pos.x = player->position.x - 30;
		pos.y = player->position.y - 30;
		return pos;
	}
	pos.x = player->position.x - 20;
	pos.y = player->position.y;
	return  pos;
}

void	update_trigger(player_t *player)
{
	for (int i = 0; i < 5; i++) {
		sfRectangleShape_setPosition(player->attack_collider[i],
			get_collider_position(player, i));
	}
}