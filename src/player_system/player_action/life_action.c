/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** player
*/

#include "lib_graph.h"

void		cor_set_player_life(player_t *self, int delta)
{
	int	tmp_delta;

	if (!self)
		return;
	if (delta > 0) {
		if (delta + self->life > BASE_LIFE) {
			//full life effect
		} else {
			self->life += abs(delta);
		}
	} else if (delta < 0) {
		tmp_delta = abs(delta);
		if (self->life - tmp_delta < 0) {
			//dead effect
		} else {
			self->life -= tmp_delta;
		}
	}
}
