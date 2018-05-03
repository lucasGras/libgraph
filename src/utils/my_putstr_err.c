/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** task02
*/

#include "my.h"
#include <unistd.h>

int	my_putstr_err(char *str)
{
	int i = 0;

	while (str && str[i] != '\0') {
		write(2, &str[i], 1);
		i++;
	}
	return (0);
}
