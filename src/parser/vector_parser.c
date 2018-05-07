/*
** EPITECH PROJECT, 2018
** vector
** File description:
** parser
*/

#include <SFML/Graphics/Rect.h>
#include "lib_graph.h"

sfIntRect		get_rect_by_vector(sfVector2i vector)
{
	sfIntRect	rect;

	rect.width = vector.x;
	rect.height = vector.y;
	rect.left = 0;
	rect.top = 0;
	return  rect;
}

sfVector2i		get_vector2i_str(char *str)
{
	sfVector2i	vector;
	int		k;
	char		**tab = NULL;

	for (k = 0; str && str[k]; k++)
		str[k] = (char)((str[k] == ',') ? ' ' : str[k]);
	tab = my_str_to_word_array(str);
	vector.x = my_getnbr(tab[0]);
	vector.y = my_getnbr(tab[1]);
	for (k = 0; tab[k]; k++)
		free(tab[k]);
	free(tab);
	return vector;
}

sfVector2f		get_vector2f_str(char *str)
{
	sfVector2f	vector;
	int		k;
	char		**tab = NULL;

	for (k = 0; str && str[k]; k++)
		str[k] = (char)((str[k] == ',') ? ' ' : str[k]);
	tab = my_str_to_word_array(str);
	vector.x = (float)my_getnbr(tab[0]);
	vector.y = (float)my_getnbr(tab[1]);
	for (k = 0; tab[k]; k++)
		free(tab[k]);
	free(tab);
	return vector;
}
