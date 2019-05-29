/*
** EPITECH PROJECT, 2019
** game
** File description:
** game
*/

#include "my.h"
#include "matchstick.h"
#include <unistd.h>
#include "get_next_line.h"

int play_game(char **tab, int size, int max_remove_match)
{
    display_tab(tab);
    while (42){
        my_printf("\nYour turn:\n");
        if ((tab = player_turn(size, max_remove_match, tab)) == NULL)
            return (0);
        if (check_win(tab) == 1)
            return (2);
        my_printf("\nAI's turn...\n");
        tab = better_ai(max_remove_match, tab);
        if (check_win(tab) == 1)
            return (1);
    }
    return (0);
}
