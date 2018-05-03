/*
** EPITECH PROJECT, 2018
** particle
** File description:
** conf
*/

#include "lib_graph.h"

void			init_particle_array(particle_system_t *system_p)
{
	int	i = 0;
	int	total = system_p->nb_particles;

	system_p->particle_array = malloc(sizeof(particle_t) * total);
	while (i < total) {
		system_p->particle_array[i] = init_particle(system_p);
		i++;
	}
}

void			set_systemp_function(particle_system_t *system_p)
{
	system_p->play_system = cor_play_system;
	system_p->reset_system = cor_reset_system;
	system_p->reset_system_rgbalpha = cor_reset_system_rbgalpha;
}

system_type_t		get_system_type(char *value)
{
	system_type_t	types[] = {EXPL, COS, DOWN};
	char		*char_types[] = {"explosion", "cosinus", "down", NULL};
	int		i = 0;

	while (char_types[i]) {
		if (my_strcmp(char_types[i], value) == 0)
			return types[i];
		i++;
	}
	return (system_type_t)-1;
}

void			particle_conf_file(FILE *fd,
					particle_system_t *system_p)
{
	system_p->system_name = get_fileconf_value("name", fd);
	system_p->nb_particles = my_getnbr(get_fileconf_value("nb_particle",
						fd));
	system_p->lenght = my_getnbr(get_fileconf_value("lenght", fd));
	system_p->type = get_system_type(get_fileconf_value("type", fd));
	system_p->origin = get_vector2f_str(get_fileconf_value("origin", fd));
	system_p->range = my_getnbr(get_fileconf_value("range", fd));
	system_p->min_speed = my_getnbr(get_fileconf_value("min_speed", fd));
	system_p->max_speed = my_getnbr(get_fileconf_value("max_speed", fd));
	system_p->max_rotation_speed =
		my_getnbr(get_fileconf_value("max_R_speed", fd));
	system_p->fade = get_bool_str(get_fileconf_value("fade", fd));
	system_p->txtr_path = get_fileconf_value("p_path", fd);
}

particle_system_t	init_particle_system(char *file_path,
					sfRenderWindow * window_ptr)
{
	particle_system_t	system_p;
	FILE			*fd;

	valid_conf_file(file_path, PARTICLE_SYSTEM_EXT);
	fd = fopen(file_path, "r");
	system_p.ptr = window_ptr;
	particle_conf_file(fd, &system_p);
	init_particle_array(&system_p);
	system_p.systemp_thread = NULL;
	system_p.displayed = sfFalse;
	system_p.mvt_clock = sfClock_create();
	set_systemp_function(&system_p);
	fclose(fd);
	return system_p;
}
