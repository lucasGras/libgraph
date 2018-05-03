/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** controller
*/

#include <lib_graph.h>
#include "lib_graph.h"

void			cor_set_extern_joystick(animator_t *self,
			int index, void (*func)(void *), void *arg)
{
	int	i = 0;

	if (index >= XBOX_COUNT || func == NULL || self == NULL)
		return;
	while (i < XBOX_COUNT) {
		if (self->joystickwapper[i].controller_id == index)
			break;
		i++;
	}
	self->joystickwapper[i].call = func;
	self->joystickwapper[i].argument = arg;
}

joystickwapper_t	joystickwapper(int id, void (*m_call)(void *),
							void *arg)
{
	joystickwapper_t	sub_wrapper;

	sub_wrapper.controller_id = id;
	sub_wrapper.call = m_call;
	sub_wrapper.argument = arg;
	return  sub_wrapper;
}

joystickwapper_t	*get_joystickwrapper(animator_t *self)
{
	joystickwapper_t	*wrapper = malloc(sizeof(*wrapper)
						* XBOX_COUNT);

	wrapper[0] = joystickwapper(XBOX_A, NULL, NULL);
	wrapper[1] = joystickwapper(XBOX_B, atk_sword, self);
	wrapper[2] = joystickwapper(XBOX_X, check_sword, self);
	wrapper[3] = joystickwapper(XBOX_Y, check_arrow, self);
	wrapper[4] = joystickwapper(XBOX_SELECT, NULL, NULL);
	wrapper[5] = joystickwapper(XBOX_RB, NULL, NULL);
	wrapper[6] = joystickwapper(XBOX_LB, NULL, NULL);
	return wrapper;
}
