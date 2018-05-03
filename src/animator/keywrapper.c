/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** animator
*/

#include <lib_graph.h>
#include "lib_graph.h"

void			cor_set_extern_keyboard(animator_t *self,
			sfKeyCode key, void (*func)(void *), void *arg)
{
	int	i = 0;

	if (func == NULL || self == NULL)
		return;
	while (self->keywrapper[i].call) {
		if (self->keywrapper[i].key == key)
			break;
		i++;
	}
	self->keywrapper[i].call = func;
	self->keywrapper[i].argument = arg;
}

keywrapper_t		init_wrapper(sfKeyCode code, void (*m_call)(void *),
						void *arg)
{
	keywrapper_t	wrapper;

	wrapper.key = code;
	wrapper.call = m_call;
	wrapper.argument = arg;
	return wrapper;
}

keywrapper_t		*my_keywrapper(animator_t *self)
{
	keywrapper_t	*tab = malloc(sizeof(keywrapper_t) * 10);

	tab[0] = init_wrapper(sfKeyRight, my_right, self);
	tab[1] = init_wrapper(sfKeyLeft, my_left, self);
	tab[2] = init_wrapper(sfKeyUp, my_up, self);
	tab[3] = init_wrapper(sfKeyDown, my_down, self);
	tab[4] = init_wrapper(sfKeyE, backpack, self);
	tab[5] = init_wrapper(sfKeyZ, atk_sword, self);
	tab[6] = init_wrapper(sfKeyD, check_arrow, self);
	tab[7] = init_wrapper(sfKeyQ, check_sword, self);
	tab[8] = init_wrapper(sfKeyTab, NULL, NULL);
	tab[9] = init_wrapper((sfKeyCode) - 1, NULL, NULL);
	return tab;
}