/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** task02
*/

#include "my.h"

int	my_putstr(char *str)
{
	int i = 0;

	while (str && str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
	return (0);
}
