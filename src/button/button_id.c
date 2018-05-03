/*
** EPITECH PROJECT, 2018
** id
** File description:
** button
*/

#include "lib_graph.h"

void assign_button_id(button_t *item, int m_id)
{
	if (m_id < 0 || !item)
		return;
	item->id = m_id;
}

int get_button_hovered_id(list_button_t *list, sfVector2f vector_mouse)
{
	list_button_t *tmp = list;

	while (tmp) {
		if (tmp->data->is_hovered(tmp->data, vector_mouse) == sfTrue)
			return tmp->data->id;
		tmp = tmp->next;
	}
	return -1;
}
