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

int play_game(char **tab, int size, int max_remove_match, int ai_level)
{
    display_tab(tab);
    while (42){
        my_printf("\nYour turn:\n");
        if ((tab = player_turn(size, max_remove_match, tab)) == NULL)
            return (0);
        if (check_win(tab) == 1){
            my_printf("You lost, too bad...\n");
            return (2);
        }
        my_printf("\nAI's turn...\n");
        if (ai_level == 2)
            tab = better_ai(max_remove_match, tab);
        else
            tab = ai_turn(size, max_remove_match, tab);
        if (check_win(tab) == 1){
            my_printf("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
    }
    return (0);
}

int play_game_ai(char **tab, int size, int max_remove_match, int ai_level)
{
    display_tab(tab);
    while (42){
        my_printf("\nAi 1 turn:\n");
        tab = (ai_level == 2 ? better_ai(max_remove_match, tab)\
: ai_turn(size, max_remove_match, tab));
        if (check_win(tab) == 1){
            my_printf("Ai 1 lose\n");
            return (2);
        }
        sleep(1);
        my_printf("\nAI 2 turn...\n");
        tab = (ai_level == 2 ? better_ai(max_remove_match, tab)\
: ai_turn(size, max_remove_match, tab));
        if (check_win(tab) == 1){
            my_printf("Ai 2 lose\n");
            return (1);
        }
        sleep(1);
    }
    return (0);
}

int play_game_player(char **tab, int size, int max_remove_match)
{
    display_tab(tab);
    while (42){
        my_printf("\nPlayer1 turn:\n");
        if ((tab = player_turn(size, max_remove_match, tab)) == NULL)
            return (0);
        if (check_win(tab) == 1){
            my_printf("Player1 lose\n");
            return (2);
        }
        my_printf("\nPlayer2 turn:\n");
        if ((tab = player_turn(size, max_remove_match, tab)) == NULL)
            return (0);
        if (check_win(tab) == 1){
            my_printf("Player2 lose\n");
            return (1);
        }
    }
    return (0);
}
