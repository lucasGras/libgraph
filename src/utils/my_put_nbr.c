/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** task07
*/

#include "my.h"

int	my_put_nbr(int nb)
{
	if (nb < 0) {
		nb = nb * -1;
		my_putchar('-');
	}
	if (nb >= 10) {
		my_put_nbr(nb / 10);
	}
	my_putchar((nb % 10) + '0');
	return 0;
}
