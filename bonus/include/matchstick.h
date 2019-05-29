/*
** EPITECH PROJECT, 2019
** match
** File description:
** proto
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

int play_game(char **tab, int size, int max_remove_match, int ai_level);
char **player_turn(int size, int max_remove_match, char **tab);
char **remove_match_fc(char **tab, int line, int nb_match);
char **get_game_bord(int size);
void display_tab(char **tab);
int check_win(char **tab);
char **ai_turn(int size, int max_remove_match, char **tab);
int check_error_line(int size, int line);
int check_error_line_ai(int size, int line);
int check_error_match(int max_remove_match,
int remove_match, int line, char **tab);
int check_error_match_ai(int max_remove_match,
int remove_match, int line, char **tab);
char **better_ai(int max_remove_match, char **tab);
int check_str(char *str);
int play_game_player(char **tab, int size, int max_remove_match);
int play_game_ai(char **tab, int size, int max_remove_match, int ai_level);

#endif /* !MATCHSTICK_H_ */
