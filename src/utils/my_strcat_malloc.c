/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** task02
*/

#include "my.h"
#include <stdlib.h>

int my_strlen_protect(char *str)
{
	int i = 0;

	if (!str)
		return 0;
	while (str && str[i])
		i++;
	return i;
}

void check_malloc(char *src)
{
	if (src == NULL)
		exit(84);
}

char	*my_strcat_malloc(char *dest, char *src)
{
	int len = my_strlen_protect(dest);
	int i = -1;
	char *res = malloc(sizeof(char) * (len + my_strlen_protect(src)) + 1);

	check_malloc(res);
	if (dest == NULL) {
		while (src[++i])
			res[i] = src[i];
		res[i] = '\0';
		return res;
	}
	while (dest[++i])
		res[i] = dest[i];
	i = 0;
	while (src[i] != '\0') {
		res[len + i] = src[i];
		i++;
	}
	res[len + i] = '\0';
	return res;
}
