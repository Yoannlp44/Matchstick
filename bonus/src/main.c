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

void help(void)
{
    my_printf("./matchstick [size(2/99)] ");
    my_printf(" [max_remove] [ai level(1/2)] [choose oponent");
    my_printf(" (1 = player vs ai, 2 = player vs player, 3 = ai vs ai)]\n");
}

int choose_game(int size, int max_remove, int ai_level, int choose_player)
{
    int winner = 0;
    char **tab = NULL;

    tab = get_game_bord(size);
    if (choose_player == 1)
        winner = play_game(tab, size, max_remove, ai_level);
    if (choose_player == 2)
        winner = play_game_player(tab, size, max_remove);
    if (choose_player == 3)
        winner = play_game_ai(tab, size, max_remove, ai_level);
    return (winner);
}

int main(int argc, char const *argv[])
{
    int winner = 0;

    if (argv[1] != NULL && my_strcmp(argv[1], "-h") == 0) {
        help();
        return (0);
    }
    if (argc != 5 || my_getnbr(argv[1]) <= 1 || my_getnbr(argv[1]) >= 100 \
|| my_getnbr(argv[2]) < 1 || my_getnbr(argv[3]) < 1 || my_getnbr(argv[3]) > 2\
|| my_getnbr(argv[4]) > 3 || my_getnbr(argv[4]) < 1)
        return (84);
    srand(time(NULL));
    winner = choose_game(my_getnbr(argv[1]), my_getnbr(argv[2]), \
my_getnbr(argv[3]), my_getnbr(argv[4]));
    return (winner);
}
