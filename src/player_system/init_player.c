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

sfVector2f		get_collider_size(int index, sfVector2f pos)
{
	switch (index) {
		case COLLIDER_AROUND:
			return new_vector2f(pos.x + 100, pos.y + 100);
		case COLLIDER_TOP:
			return new_vector2f(pos.x + 50, pos.y - 90);
		case COLLIDER_RIGHT:
			return new_vector2f(pos.x + 140, pos.y + 50);
		case COLLIDER_BOT:
			return new_vector2f(pos.x + 50, pos.y + 140);
		case COLLIDER_LEFT:
			return new_vector2f(pos.x - 90, pos.y + 50);
		default:
			break;
	}
	return new_vector2f(pos.x, pos.y);
}

sfRectangleShape	**get_attack_collider(player_t *self)
{
	sfRectangleShape	**shapes;

	shapes = malloc(sizeof(sfRectangleShape *) * 4);
	if (!shapes)
		return NULL;
	for (int i = 0; i < 5; i++) {
		shapes[i] = sfRectangleShape_create();
		sfRectangleShape_setOutlineThickness(shapes[i], 2);
		sfRectangleShape_setOutlineColor(shapes[i], sfGreen);
		sfRectangleShape_setSize(shapes[i],
			get_collider_size(i, self->position));
		sfRectangleShape_setPosition(shapes[i], self->position);
		sfRectangleShape_setFillColor(shapes[i], sfTransparent);
	}
	return shapes;
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
	player->attack_type = NONE;
	player->horizontal_dir = 1;
	set_function(player);
	return player;
}

player_t	*create_player(sfRenderWindow *ptr)
{
	player_t	*player = sub_player_initializer(ptr);

	player->attack_collider = get_attack_collider(player);
	player->set_inventory_state(player, INVENTORY_START_STATE);
	return player;
}