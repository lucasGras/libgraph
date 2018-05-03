/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** animator
*/

#include <SFML/Window.h>
#include <lib_graph.h>
#include "lib_graph.h"

void	cor_manage_event(animator_t *self)
{
	if (self->event->type == sfEvtKeyPressed) {
		spritesheet_mouvement(self);
		return;
	}
	if (self->event->type == sfEvtJoystickButtonPressed) {
		joystick_button_manager(self);
	}
	if (self->event->type == sfEvtJoystickMoved
		&& joystick_moved(self) == 1) {
		joystick_manager(self);
	}
}
