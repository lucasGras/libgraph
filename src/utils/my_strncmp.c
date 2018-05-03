/*
** EPITECH PROJECT, 2017
** my_strncmp
** File description:
** task06
*/

int my_strncmp(char const *str1, char const *str2, int n)
{
	while (n && *str1 && (*str1 == *str2)) {
		++str1;
		++str2;
		--n;
	}
	if (n == 0)
		return 0;
	else
		return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
