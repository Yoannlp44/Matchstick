/*
** EPITECH PROJECT, 2019
** error
** File description:
** error
*/

#include "my.h"
#include "matchstick.h"

int check_error_line(int size, int line)
{
    if (line > 0) {
        if (line > size) {
            my_printf("Error: this line is out of range\n");
            return (-1);
        }
    }
    else {
        my_printf("Error: this line is out of range\n");
        return (-1);
    }
    return (line);
}

int check_error_line_ai(int size, int line)
{
    if (line > 0) {
        if (line > size)
            return (-1);
    }
    else
        return (-1);
    return (line);
}

int check_error_match(int max_remove_match,
int remove_match, int line, char **tab)
{
    int nb_match_on_line = 0;

    if (remove_match <= 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (-1);
    }
    if (remove_match > max_remove_match) {
        my_printf("Error: you cannot ");
        my_printf("remove more than %d matches per turn\n", max_remove_match);
        return (-1);
    }
    for (int i = 0; tab[line][i]; i++)
        if (tab[line][i] == '|')
            nb_match_on_line++;
    if (remove_match > nb_match_on_line){
        my_printf("Error: not enough matches on this line\n");
        return (-1);
    }
    return (remove_match);
}

int check_error_match_ai(int max_remove_match,
int remove_match, int line, char **tab)
{
    int nb_match_on_line = 0;

    if (remove_match <= 0)
        return (-1);
    if (remove_match > max_remove_match)
        return (-1);
    for (int i = 0; tab[line][i]; i++)
        if (tab[line][i] == '|')
            nb_match_on_line++;
    if (remove_match > nb_match_on_line)
        return (-1);
    return (remove_match);
}