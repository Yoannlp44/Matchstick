/*
** EPITECH PROJECT, 2019
** ai
** File description:
** ai
*/

#include "my.h"
#include "matchstick.h"
#include <stdlib.h>

int count_all_matches(char **tab)
{
    int matches = 0;

    for (int i = 0; tab[i]; i++)
        for (int j = 0; tab[i][j]; j++)
            tab[i][j] == '|' ? matches++ : 0;
    return (matches);
}

int check_better_option(int nb_match, \
int *matches_to_remove, int max_remove_match)
{
    if (*matches_to_remove == 0)
        return (-1);
    while (*matches_to_remove > max_remove_match)
        (*matches_to_remove)--;
    while (*matches_to_remove > 0 && \
((nb_match - *matches_to_remove) % 2) != 1)
        (*matches_to_remove)--;
    if (nb_match == 1){
        (*matches_to_remove) = 1;
        return (0);
    }
    if ((*matches_to_remove > 0 && \
(nb_match - *matches_to_remove) % 2) == 1)
        return (0);
    return (-1);
}

char **better_ai2(int matches, int line, char **tab, int max_remove_match)
{
    int size = 0;
    int i = 0;

    for (; tab[i]; i++);
    size = i - 2;
    if (matches == 0 || line == 0) {
        tab = ai_turn(size, max_remove_match, tab);
        return (tab);
    }
    tab = remove_match_fc(tab, line, matches);
    my_printf("AI removed %d match(es) from line %d\n", matches, line);
    display_tab(tab);
    return (tab);
}

char **better_ai(int max_remove_match, char **tab)
{
    int nb_matches = 0;
    int line = 0;
    int matches = 0;

    nb_matches = count_all_matches(tab);
    for (int i = 0; tab[i]; i++){
        for (int j = 0; tab[i][j]; j++)
            tab[i][j] == '|' ? matches++ : 0;
        if (check_better_option(nb_matches, \
&matches, max_remove_match) == 0){
            line = i;
            break;
        }
        matches = 0;
    }
    tab = better_ai2(matches, line, tab, max_remove_match);
    return (tab);
}

char **ai_turn(int size, int max_remove_match, char **tab)
{
    int line = random() % (size) + 1;
    int remove_match = random() % (max_remove_match) + 1;

    while ((line = check_error_line_ai(size, line)) == -1)
        line = random() % (size) + 1;
    while ((remove_match \
    = check_error_match_ai(max_remove_match, remove_match, line, tab)) == -1){
        line = random() % (size) + 1;
        remove_match = random() % (max_remove_match) + 1;
    }
    tab = remove_match_fc(tab, line, remove_match);
    my_printf("AI removed %d match(es) from line %d\n", remove_match, line);
    display_tab(tab);
    return (tab);
}
