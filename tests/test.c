/*
** EPITECH PROJECT, 2018
** unit test
** File description:
** unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "matchstick.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(matchtick, getbord)
{
    char **tab = NULL;

    tab = get_game_bord(3);
    cr_assert_str_eq(tab[0], "*******");
    cr_assert_str_eq(tab[1], "*  |  *");
    cr_assert_str_eq(tab[2], "* ||| *");
    cr_assert_str_eq(tab[3], "*|||||*");
    cr_assert_str_eq(tab[4], "*******");
}

Test(matchtick, remove_match)
{
    char **tab = NULL;

    tab = get_game_bord(3);
    tab = remove_match_fc(tab, 2, 3);
    cr_assert_str_eq(tab[0], "*******");
    cr_assert_str_eq(tab[1], "*  |  *");
    cr_assert_str_eq(tab[2], "*     *");
    cr_assert_str_eq(tab[3], "*|||||*");
    cr_assert_str_eq(tab[4], "*******");
}

Test(matchtick, check_win)
{
    char **tab = NULL;
    int win = 0;

    tab = get_game_bord(3);
    tab = remove_match_fc(tab, 2, 3);
    tab = remove_match_fc(tab, 1, 1);
    tab = remove_match_fc(tab, 3, 5);
    win = check_win(tab);
    cr_assert_eq(win, 1);
}

Test(matchtick, check_win_2)
{
    char **tab = NULL;
    int win = 0;

    tab = get_game_bord(3);
    tab = remove_match_fc(tab, 2, 3);
    tab = remove_match_fc(tab, 1, 1);
    win = check_win(tab);
    cr_assert_eq(win, 0);
}

Test(matchtick, check_error_line)
{
    int check = 0;

    check = check_error_line(3, 3);
    cr_assert_eq(check, 3);
}

Test(matchtick, check_error_line2)
{
    int check = 0;

    check = check_error_line(3, 4);
    cr_assert_eq(check, -1);
}

Test(matchtick, check_error_match)
{
    char **tab = NULL;
    int check = 0;

    tab = get_game_bord(3);
    check = check_error_match(3, 3, 1, tab);
    cr_assert_eq(check, -1);
}

Test(matchtick, check_error_match2)
{
    char **tab = NULL;
    int check = 0;

    tab = get_game_bord(3);
    check = check_error_match(3, 1, 1, tab);
    cr_assert_eq(check, 1);
}

Test(matchtick, check_error_match3)
{
    char **tab = NULL;
    int check = 0;

    tab = get_game_bord(3);
    check = check_error_match(3, 5, 3, tab);
    cr_assert_eq(check, -1);
}

Test(matchtick, check_str)
{
    int check = 0;

    check = check_str("aze\n");
    cr_assert_eq(check, 1);
}

Test(matchtick, check_str2)
{
    int check = 0;

    check = check_str("12\n");
    cr_assert_eq(check, 0);
}