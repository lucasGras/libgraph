/*
** EPITECH PROJECT, 2018
** particle
** File description:
** mvt
*/

#include "lib_graph.h"

rgb_t		create_rgb(int m_r, int m_g, int m_b)
{
	rgb_t	rgb;

	rgb.r = m_r;
	rgb.g = m_g;
	rgb.b = m_b;
	return rgb;
}

void		set_color_particles(particle_system_t *self, rgb_t color)
{
	int	i = 0;

	while (i < self->nb_particles) {
		sfSprite_setColor(self->particle_array[i].sprite,
			sfColor_fromRGB((sfUint8)color.r,
				(sfUint8)color.g, (sfUint8)color.b));
		i++;
	}
}

void		color_over_time(particle_system_t *self,
				rgb_t base, rgb_t new_color)
{
	int		step = 100;
	int		red_step_amount = (base.r - new_color.r) / step;
	int		green_step_amount = (base.g - new_color.g) / step;
	int		blue_step_amount = (base.b - new_color.b) / step;
	static rgb_t	tmp_rgb;
	static int	step_offset = 0;

	if (step_offset == step)
		return;
	if (step_offset == 0) {
		tmp_rgb.r = base.r;
		tmp_rgb.g = base.g;
		tmp_rgb.b = base.b;
	}
	tmp_rgb.r += red_step_amount;
	tmp_rgb.g += green_step_amount;
	tmp_rgb.b += blue_step_amount;
	set_color_particles(self, tmp_rgb);
	step_offset++;
}
