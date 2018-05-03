/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** inventory
*/

#include "lib_graph.h"

inventory_item_t		get_item_by_name(player_t *self, char *name)
{
	inventory_t	*tmp = self->inventory;

	while (tmp) {
		if (my_strcmp(tmp->item.name, name) == 0)
			return tmp->item;
		tmp = tmp->next;
	}
	return tmp->item;
}

void		add_item_in_inventory(inventory_t **list, char *m_name,
				int m_damage, int m_magic_damage)
{
	inventory_t	*tmp = *list;
	inventory_t	*new_item = malloc(sizeof(*new_item));

	new_item->item.name = my_strcat_malloc(NULL, m_name);
	new_item->item.damage = m_damage;
	new_item->item.magic_damage = m_magic_damage;
	new_item->item.item_sprite = sfSprite_create();
	new_item->item.item_texture = sfTexture_createFromFile(
		get_item_visualizer(m_name), NULL);
	new_item->next = NULL;
	if ((*list) == NULL) {
		*list = new_item;
	} else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_item;
	}
}

void		cor_set_inventory_state(player_t *self, int state)
{
	if (!self)
		return;
	if (state == INVENTORY_START_STATE) {
		self->add_item(self, "Hand", 1, 0);
		self->curent_item = get_item_by_name(self, "Hand");
	}
}

void		cor_add_item(player_t *self, char *m_name,
				int m_damage, int m_magic_damage)
{
	if (!m_name || m_damage < 0 || m_magic_damage < 0)
		return;
	if (self->current_inventory_size == self->max_inventory_size)
		return;
	add_item_in_inventory(&self->inventory, m_name,
		m_damage, m_magic_damage);

}

void		cor_set_inventory_size(player_t *self, int m_size)
{
	if (m_size > 0)
		self->max_inventory_size = m_size;
}
