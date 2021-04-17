/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** copy a string with another
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
