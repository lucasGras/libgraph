/*
** EPITECH PROJECT, 2018
** random
** File description:
** time
*/

#include "lib_graph.h"

int	get_random_int_range(int min, int max)
{
	int	random;

	random = rand() % (max - min + 1) + min;
	return random;
}

int	get_random_int(void)
{
	return rand();
}

float	get_random_float_range(float min, float max)
{
	float	random;

	random = rand() / (float)MAX_RSPEED;
	return min + random * (max - min);
}
