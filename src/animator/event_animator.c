/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** animator
*/

#include <SFML/Window.h>
#include <lib_graph.h>
#include "lib_graph.h"

void	cor_manage_event(animator_t *self, sfEventType event)
{
	if (event == sfEvtKeyPressed) {
		spritesheet_mouvement(self);
		return;
	}
	if (event == sfEvtJoystickButtonPressed) {
		joystick_button_manager(self);
	}
}
