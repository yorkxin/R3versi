/* vector.c */
VECTOR vPlus(VECTOR a, VECTOR b);
VECTOR vMinus(VECTOR a, VECTOR b);
VECTOR vMultiplyConst(VECTOR a, char b);

int vCmp(VECTOR a, VECTOR b);

/* reversi-core.c */
int reversi_available_to_put(REVERSI_GAME *game);
void reversi_initialize_game(REVERSI_GAME *game);
void reversi_put(REVERSI_GAME *game);
void reversi_do_reverse(REVERSI_GAME *game);
void reversi_change_turn(REVERSI_GAME *game);
void reversi_find_available(REVERSI_GAME *game);
void reversi_counter(REVERSI_GAME *game);
char reversi_find_existance(REVERSI_GAME *game, REVERSI_STAT stat);
char reversi_is_cursor_on_wall(VECTOR cursor, int queenstep);

void reversi_reverse_route( \
    REVERSI_GAME *game, VECTOR cstart, VECTOR cend, VECTOR vector);

void reversi_map_replace( \
    REVERSI_GAME *game, REVERSI_STAT find, REVERSI_STAT target);

VECTOR reversi_find_contiunity_vectorwise( \
    REVERSI_GAME *game, VECTOR curr,  \
    int qs, REVERSI_STAT target);

REVERSI_STAT reversi_get_opposite_turn(REVERSI_STAT turn);
REVERSI_STAT reversi_whois_winner(REVERSI_GAME *game);

/* visio.c */
void wprintw_attr(WINDOW *win, int attr, char *string);

void reversi_window_print_stat(WINDOW *win, REVERSI_STAT stat);
void reversi_window_print_board(WINDOW *win, REVERSI_GAME *game);
void reversi_window_print_panel(WINDOW *win, REVERSI_GAME *game);
void reversi_window_print_counter(WINDOW *win, REVERSI_GAME *game);
char reversi_window_game_over(WINDOW *win, REVERSI_GAME *game);

/* VECTOR reversi_cursor_to_window_pos(VECTOR cursor); */
VECTOR reversi_get_window_pos_by_cursor (VECTOR cursor);
VECTOR reversi_window_handle_keypress(WINDOW *win, \
    REVERSI_GAME *game, int ch);
