/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** controller
*/

#include <lib_graph.h>
#include "lib_graph.h"

int		joystick_moved(animator_t *self)
{
	float		axis_x = sfJoystick_getAxisPosition(0,
							sfJoystickX);
	float		axis_y = sfJoystick_getAxisPosition(0,
							sfJoystickY);
	sfVector2f	axis_vector = {axis_x, axis_y};

	(void)self;
	if (axis_vector.x > 50 || axis_vector.x < -50)
		return 1;
	else if (axis_vector.y > 50 || axis_vector.y < -50)
		return 1;
	return -1;
}

void		joystick_axis_x(animator_t *self, sfVector2f axis_vector)
{
	if (axis_vector.x > 50) {
		my_right(self);
	} else if (axis_vector.x < -50) {
		my_left(self);
	}
}

void		joystick_axis_y(animator_t *self, sfVector2f axis_vector)
{
	if (axis_vector.y > 50) {
		my_down(self);
	} else if (axis_vector.y < -50) {
		my_up(self);
	}
}

void		joystick_manager(animator_t *self)
{
	float		axis_x = sfJoystick_getAxisPosition(0,
							sfJoystickX);
	float		axis_y = sfJoystick_getAxisPosition(0,
							sfJoystickY);
	sfVector2f	axis_vector = {axis_x, axis_y};

	if (self->move_rect >= 5)
		self->move_rect = 0;
	sfSprite_setTextureRect(self->sprite, self->rect);
	sfSprite_setPosition(self->sprite, self->pos);
	if (axis_vector.x > 50 || axis_vector.x < -50)
		joystick_axis_x(self, axis_vector);
	else if (axis_vector.y > 50 || axis_vector.y < -50)
		joystick_axis_y(self, axis_vector);
	self->move_rect++;
	wait_for_seconds(0.05);
}

void		joystick_button_manager(animator_t *self)
{
	int	i = 0;

	if (!self)
		return;
	while (i < XBOX_COUNT) {
		if (sfJoystick_isButtonPressed(0,
			(unsigned int)self->joystickwapper[i].controller_id)) {
			self->joystickwapper[i].call
				(self->joystickwapper[i].argument);
			break;
		}
		i++;
	}
}
