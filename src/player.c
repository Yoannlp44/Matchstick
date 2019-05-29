/*
** EPITECH PROJECT, 2019
** player
** File description:
** player
*/

#include <unistd.h>
#include "get_next_line.h"
#include "my.h"
#include "matchstick.h"
#include <stdio.h>

char *get_player_input(void)
{
    char * line = NULL;
    size_t len = 0;
    int result;

    result = getline(&line, &len, stdin);
    if (result == -1)
        return (NULL);
    return (line);
}

int check_str(char *str)
{
    for (int i = 0; str[i] != '\n'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            my_printf("Error: invalid input (positive number expected)\n");
            return (1);
        }
    }
    return (0);
}

int get_player_line(int size)
{
    int line = 0;
    char *str = NULL;

    my_printf("Line: ");
    if ((str = get_player_input()) == NULL)
        return (-1);
    while ((check_str(str) != 0) \
|| (line = check_error_line(size, my_getnbr(str))) == -1){
        my_printf("Line: ");
        if ((str = get_player_input()) == NULL)
            return (-1);
    }
    return (line);
}

char **player_turn(int size, int max_remove_match, char **tab)
{
    char *str = NULL;
    int line = 0;
    int remove_match = 0;

    if ((line = get_player_line(size)) == -1)
        return (NULL);
    my_printf("Matches: ");
    if ((str = get_player_input()) == NULL)
        return (NULL);
    if ((check_str(str) != 0) || (remove_match = \
check_error_match(max_remove_match, my_getnbr(str), line, tab)) == -1){
        tab = player_turn(size, max_remove_match, tab);
        return (tab);
    }
    tab = remove_match_fc(tab, line, remove_match);
    my_printf("Player removed %d match(es) from line %d\n", remove_match, line);
    display_tab(tab);
    return (tab);
}
