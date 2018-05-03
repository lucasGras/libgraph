/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** task01
*/

char		*my_strcpy(char *dest, char *src)
{
	int	i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}

char		*my_strncpy(char *dest, char *src, int n)
{
	int	i = 0;

	while (src[i] != '\0') {
		if (i == n)
			break;
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}
