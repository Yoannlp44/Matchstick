/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#include <unistd.h>
#include "my.h"
#include <stdlib.h>

char **remove_match_fc(char **tab, int line, int nb_match)
{
    int i = 1;

    for (;tab[line][i] != '|'; i++);
    for (;tab[line][i] == '|'; i++);
    for (int j = 0; j < nb_match; j++, i--)
        tab[line][i - 1] = ' ';
    return (tab);
}

char **get_game_bord(int size)
{
    char **tab = malloc(sizeof(char *) * (size + 3));
    int j = 1;
    int space = size;
    int i = 0;

    for (i = 0; i < size + 1; i++)
        tab[i] = malloc(sizeof(char) * (size + size + 2));
    for (i = 0; i < (size + size + 1); i++)
        tab[0][i] = '*';
    tab[0][i] = '\0';
    for (int i = 1; i < size + 1; i++){
        tab[i][0] = '*';
        for (j = 1; j < size + size; j++)
            tab[i][j] = j > (size + size) - space || j < space ? ' ' : '|';
        tab[i][j] = '*';
        tab[i][j + 1] = '\0';
        space--;
    }
    tab[size + 1] = tab[0];
    tab[size + 2] = NULL;
    return (tab);
}

void display_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        my_printf("%s\n", tab[i]);
}

int count_matchs(char **tab, int i, int j, int nb_match)
{
    if (tab[i][j] == '|')
        nb_match++;
    return (nb_match);
}

int check_win(char **tab)
{
    int nb_match = 0;
    int i = 0;
    int j = 0;

    while (tab[i]){
        while (tab[i][j]) {
            nb_match = count_matchs(tab, i, j, nb_match);
            j++;
        }
        j = 0;
        i++;
    }
    if (nb_match == 0)
        return (1);
    return (0);
}
