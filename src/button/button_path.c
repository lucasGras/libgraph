/*
** EPITECH PROJECT, 2018
** path
** File description:
** button
*/

#include "lib_graph.h"

int		cor_image(char *ext)
{
	if (!ext)
		return -1;
	return (my_strcmp(ext, EXT_FILE) == 0) ? 1 : -1;
}

char		*epure_path(char *path)
{
	int	i = 0;
	char	*epured = my_strcat_malloc(NULL, path);

	while (epured && epured[i]) {
		if (cor_image(&epured[i]) == 1)
			break;
		i++;
	}
	if (!epured) {
		my_putstr("Error: Invalid texture type (must be png)\n");
		exit(84);
	}
	epured[i] = '\0';
	return epured;
}

char		*get_extension(char *path, char *ext)
{
	if (!path || !ext)
		return NULL;
	return (my_strcat_malloc(path, ext));
}

void		set_path(button_t *self, char *path)
{
	char	*epured_path = NULL;

	if (!path)
		return;
	epured_path = epure_path(path);
	self->path_base = path;
	self->path_hover = get_extension(epured_path, EXT_H);
	self->path_click = get_extension(epured_path, EXT_C);
}
