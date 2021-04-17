/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** main
*/

#include "../lib/my.h"
#include <ncurses.h>

int veref_3(char *str)
{
    int a = 0;
    int b = 0;

    for (int nb = 0; str[nb] != '\0'; nb++) {
        if (str[nb] == 'O')
            a++;
    }
    for (int nb = 0; str[nb] != '\0'; nb++) {
        if (str[nb] == 'X')
            b++;
    }
    if (a == b)
        return (1);
    return (0);
}

int veref_2(char *str)
{
    for (int nb = 0; str[nb] != '\0'; nb++) {
        if (str[nb] == 'O')
            return (0);
    }
    return (1);
}

char *spire(int key, char *str, char *str_copy)
{
    int a = 0;

    for (; str[a] != 'P'; a++) {}
    if (key == KEY_UP)
        return (move_curseur(str, 1, a, str_copy));
    else if (key == KEY_DOWN)
        return (move_curseur(str, 2, a, str_copy));
    if (key == KEY_LEFT)
        return (move_curseur(str, 3, a, str_copy));
    else if (key == KEY_RIGHT)
        return (move_curseur(str, 4, a, str_copy));
    return (str);
}

int my_sokoban(char *str)
{
    int key = 0;
    char *str_copy = my_strcpy(str_copy, str);

    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    while (1) {
        clear();
        mvprintw(LINES = 0, COLS = 0, str);
        refresh();
        if (veref_2(str) == 1)
            break;
        key = getch();
        if (key == ' ')
            str = my_strcpy(str, str_copy);
        else if (key == KEY_BACKSPACE)
            break;
        str = spire(key, str, str_copy);
    }
    endwin();
    return (0);
}

int main(int ac, char **av)
{
    int fd = 0;
    struct stat sb;

    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            tiret_h();
            return (0);
        }
        stat(av[1], &sb);
        char *str = malloc(sizeof(char) * sb.st_size + 1);
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
            return (84);
        read(fd, str, sb.st_size);
        if (veref_3(str) == 0)
            return (84);
        my_sokoban(str);
        close(fd);
    } else
        return (84);
    return (0);
}