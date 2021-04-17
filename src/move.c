/*
** EPITECH PROJECT, 2021
** ...
** File description:
** ...
*/

#include "../lib/my.h"

int veref(char *str, char *str_copy)
{
    for (int nb = 0; str[nb] != '\0'; nb++) {
        if (str[nb] == ' ' && str_copy[nb] == 'O') {
            return (nb);
        }
    }
    return (0);
}

char *move_one(char *s, int nb, int a, int b)
{
    if (s[a - b] != '#' && nb == 1) {
        if (s[a - b] == 'X' && s[a - b - b] != '#' && s[a - b - b] != 'X') {
            s[a] = ' ';
            s[a - b] = 'P';
            s[a - b - b] = 'X';
        } else if (s[a - b] != 'X') {
            s[a] = ' ';
            s[a - b] = 'P';
        }
    } else if (s[a + b] != '#' && nb == 2) {
        if (s[a + b] == 'X' && s[a + b + b] != '#' && s[a + b + b] != 'X') {
            s[a] = ' ';
            s[a + b] = 'P';
            s[a + b + b] = 'X';
        } else if (s[a + b] != 'X') {
            s[a] = ' ';
            s[a + b] = 'P';
        }
    }
    return (s);
}

char *move_two(char *str, int nb, int a, int b)
{
    if (str[a - 1] != '#' && nb == 3) {
        if (str[a - 1] == 'X' && str[a - 2] != '#' && str[a - 2] != 'X') {
            str[a] = ' ';
            str[a - 1] = 'P';
            str[a - 2] = 'X';
        } else if (str[a - 1] != 'X') {
            str[a] = ' ';
            str[a - 1] = 'P';
        }
    } else if (str[a + 1] != '#' && nb == 4) {
        if (str[a + 1] == 'X' && str[a + 2] != '#' && str[a + 2] != 'X') {
            str[a] = ' ';
            str[a + 1] = 'P';
            str[a + 2] = 'X';
        } else if (str[a + 1] != 'X') {
            str[a] = ' ';
            str[a + 1] = 'P';
        }
    }
    return (str);
}

char *move_curseur(char *s, int nb, int a, char *str_copy)
{
    int b = 0;

    for (; s[b] != '\n'; b++) {}
    b++;
    s = move_one(s, nb, a, b);
    s = move_two(s, nb, a, b);
    b = veref(s, str_copy);
    if (b != 0) {
        s[b] = 'O';
    }
    return (s);
}