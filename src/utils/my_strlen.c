/*
** EPITECH PROJECT, 2017
** strlen
** File description:
** lib
*/

int my_strlen(char *str)
{
	int i = 0;

	while (str && str[i])
		i++;
	return i;
}
