/*
** EPITECH PROJECT, 2018
** pnj
** File description:
** init
*/

#include "lib_graph.h"

int		seek_index(char *buff, char *index)
{
	int	i = 0;

	while (buff && buff[i]) {
		if (my_strncmp(&buff[i], index, my_strlen(index)) == 0)
			return 1;
		i++;
	}
	return -1;
}

int		endof_index_value(char *buff)
{
	int	i = 0;

	while (buff && buff[i]) {
		if (buff[i] == ')')
			return 1;
		i++;
	}
	return -1;
}

char		*get_index_value(FILE *fd, char *buff_index, char *index)
{
	char	*value = NULL;
	char	*buff = NULL;
	size_t	len = 0;
	int	read = 1;

	value = my_strcat_malloc(value, &buff_index[my_strlen(index) + 2]);
	while (read != -1) {
		if (endof_index_value(value) > 0)
			break;
		read = getline(&buff, &len, fd);
		value = my_strcat_malloc(value, buff);
	}
	value[my_strlen(value) - 2] = 0;
	return value;
}

char		*get_fileconf_value(char *index, FILE *fd)
{
	char	*buff = NULL;
	size_t	len = 0;
	int	read = 1;

	while (read != -1 && my_strcmp(buff, PNJ_EOF) != 0) {
		read = getline(&buff, &len, fd);
		if (seek_index(buff, index) == 1)
			return get_index_value(fd, buff, index);
	}
	return NULL;
}
