/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** player
*/

#include "lib_graph.h"

void		cor_display_inventory(void *data)
{
	player_t	*self = (player_t *)data;

	self->inventory_displayed =
		(self->inventory_displayed) ? sfFalse : sfTrue;
	wait_for_seconds(0.25);
}

char		*get_item_visualizer(char *name)
{
	char	*texture_str[] = {
		ITEM_EXCALIBUR_TXTR, ITEM_HAND_TXTR, ITEM_BOOK_TXTR, NULL
	};
	char	*item_name[] = {
		"Excalibur", "Hand", "MagicBook" , NULL
	};
	int	i = 0;

	while (item_name[i]) {
		if (my_strcmp(item_name[i], name) == 0)
			return texture_str[i];
		i++;
	}
	return NULL;
}

void		cor_change_item(void *data)
{
	player_t		*self = (player_t *)data;
	inventory_t		*tmp = self->inventory;
	inventory_item_t	current;

	while (tmp) {
		if (tmp->item.name == self->curent_item.name)
			break;
		tmp = tmp->next;
	}
	if (tmp && tmp->next == NULL)
		current = self->inventory->item;
	else
		current = tmp->next->item;
	self->curent_item = current;
	wait_for_seconds(0.5);
}
