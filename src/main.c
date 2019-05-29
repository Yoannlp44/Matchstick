/*
** EPITECH PROJECT, 2019
** bootstrap
** File description:
** bootstap
*/

#include <unistd.h>
#include "my.h"
#include "matchstick.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    char **tab = NULL;
    int winner = 0;

    if (argc != 3 || my_getnbr(argv[1]) <= 1 || my_getnbr(argv[1]) >= 100 \
|| my_getnbr(argv[2]) < 1)
        return (84);
    srand(time(NULL));
    tab = get_game_bord(my_getnbr(argv[1]));
    winner = play_game(tab, my_getnbr(argv[1]), my_getnbr(argv[2]));
    if (winner == 1)
        my_printf("I lost... snif... but I'll get you next time!!\n");
    else if (winner == 2)
        my_printf("You lost, too bad...\n");
    return (winner);
}
