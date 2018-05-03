/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** player
*/

#include <lib_graph.h>
#include "lib_graph.h"

static void	set_function(player_t *player)
{
	player->add_item = cor_add_item;
	player->set_inventory_size = cor_set_inventory_size;
	player->set_inventory_state = cor_set_inventory_state;
	player->set_life = cor_set_player_life;
	player->set_mana = cor_set_player_mana;
	player->change_item = cor_change_item;
	player->inventory_status = cor_display_inventory;
}

player_t	*sub_player_initializer(sfRenderWindow *ptr)
{
	player_t	*player = malloc(sizeof(player_t));

	player->life = BASE_LIFE;
	player->mana = BASE_MANA;
	player->xp = BASE_XP;
	player->max_inventory_size = BASE_INVENTORY_SIZE;
	player->current_inventory_size = 0;
	player->inventory = NULL;
	player->position.x = 0;
	player->position.y = 0;
	player->inventory_visual = init_inventory_visual();
	player->window_ptr = ptr;
	player->inventory_displayed = sfFalse;
	set_function(player);
	return player;
}

player_t	*create_player(sfRenderWindow *ptr)
{
	player_t	*player = sub_player_initializer(ptr);

	player->set_inventory_state(player, INVENTORY_START_STATE);
	return player;
}
