/*
** EPITECH PROJECT, 2020
** My.h
** File description:
** Header on my lib
*/

#ifndef MY_H
#define MY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>

int my_strlen(char const *str);
int my_putstr(char const *str);
void tiret_h(void);
char *move_curseur(char *str, int nb, int a, char *str_copy);
char *my_strcpy(char *dest, char const *src);

#endif
