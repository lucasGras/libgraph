/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** task05
*/

#include "my.h"

int get_sign(char *str)
{
	int i = 0;
	int neg = 0;

	while (str && str[i]) {
		if (str[i] == '-')
			neg++;
		i++;
	}
	if (neg % 2 == 0)
		return 1;
	else
		return 0;
}

int get_sign_num(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	else if (c == '-' || c == '+')
		return 2;
	else
		return 0;
}

int my_getnbr(char *str)
{
	int i = 0;
	int nb = 0;

	if (!str)
		return 0;
	while (get_sign_num(str[i]) == 2) {
		i++;
	}
	while (get_sign_num(str[i]) == 1) {
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	if (get_sign(str) == 0) {
		nb *= -1;
	}
	return nb;
}
