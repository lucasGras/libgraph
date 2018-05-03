/*
** EPITECH PROJECT, 2017
** my_strcmp
** File description:
** task05
*/

int		my_strcmp(char *s1, char *s2)
{
	int	similar = 0;

	if (!s1 || !s2)
		return (-1);
	while (s1[similar] == s2[similar] && s1[similar] != '\0')
		similar = similar + 1;
	return s1[similar] - s2[similar];
}
