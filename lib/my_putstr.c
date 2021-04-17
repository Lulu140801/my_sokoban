/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** Display the characters of a string
*/

#include "my.h"

int my_putstr(char const *str)
{
    int read = 0;

    while (str[read] != '\0') {
        write(1, &str[read], 1);
        read++;
    }
    return (0);
}

