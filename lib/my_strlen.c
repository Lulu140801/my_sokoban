/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** calculator of the charactere int the string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        a++;
    }
    return (a);
}