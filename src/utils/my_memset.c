/*
** EPITECH PROJECT, 2018
** memset
** File description:
** lib
*/

#include "my.h"

void	my_memset(char *buff, int val)
{
	int	i = -1;

	while (buff && buff[++i])
		buff[i] = val;
}
