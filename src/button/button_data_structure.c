/*
** EPITECH PROJECT, 2018
** data structure
** File description:
** button
*/

#include "lib_graph.h"

void		display_button_list(list_button_t *list,
			sfRenderWindow *win)
{
	list_button_t	*tmp = list;

	while (tmp) {
		display_button(tmp->data, win);
		tmp = tmp->next;
	}
}

void		add_button_in_list(list_button_t **list, button_t *item)
{
	list_button_t	*node = NULL;

	node = malloc(sizeof(list_button_t));
	node->data = item;
	node->next = NULL;
	if (!(*list)) {
		(*list) = node;
		return;
	}
	node->next = (*list);
	(*list) = node;
}
