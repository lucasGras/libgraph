/*
** EPITECH PROJECT, 2017
** header
** File description:
** lib
*/

#ifndef MY_H
#define MY_H

void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char *str);
int my_getnbr(char *str);
int my_putstr(char *);
int my_strcmp(char *, char *);
char *my_strcat_malloc(char *, char *);
char *my_strcpy(char *, char *);
void my_memset(char *, int);
char *my_strncpy(char *, char *, int);
int my_strncmp(char *, char *, int);
char **my_str_to_word_array(char *);
char *clear_str(char *);

#endif
