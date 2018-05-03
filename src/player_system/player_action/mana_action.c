/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** player
*/

#include "lib_graph.h"

void		cor_set_player_mana(player_t *self, int delta)
{
	int	tmp_delta;

	if (!self)
		return;
	if (delta > 0) {
		if (delta + self->mana > BASE_MANA) {
			//full mana effect
		} else {
			self->mana += abs(delta);
		}
	} else if (delta < 0) {
		tmp_delta = abs(delta);
		if (self->mana - tmp_delta < 0) {
			//no mana effect
		} else {
			self->mana -= tmp_delta;
		}
	}
}
