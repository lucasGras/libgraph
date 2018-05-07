/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** player
*/

#include <lib_graph.h>
#include "lib_graph.h"

void	display_enemy(enemy_t *enemy)
{
	if (enemy->alive) {
		sfRenderWindow_drawRectangleShape(enemy->window_ptr,
			enemy->box_collider, NULL);
	}
}