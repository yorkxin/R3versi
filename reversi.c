/*-------------------------------------------------------*
 * reversi.c		( Reversi Game Ver 3 )		 *
 *-------------------------------------------------------*
 * target : The main function for Terminal Reversi Game	 *
 * create : 07/11/27					 *
 * update :   /  /					 *
 * author : Chitsaou Yorkxin (u96504@csie.ntnu.edu.tw)	 *
 *-------------------------------------------------------*/

#include "reversi.h"

int
main (void)
{
  REVERSI_GAME game;

  initscr ();				/* initialze the NCURSE */
  noecho ();				/* don't echo keypresses on the scr */
  cbreak ();				/* grab F1 and others */
  start_color();			/* turn on the color macro */
  keypad (stdscr, TRUE);		/* grab HOME, END etc. */

  while (1)
  {
    reversi_initialize_game (&game);	/* initialize the game */
  
    VECTOR winpos;
  
    /* initial color pairs */
    init_pair (COLOR_ID_NONE, 	COLOR_BLACK,	COLOR_BLACK);
    init_pair (COLOR_ID_BLACK, 	COLOR_BLACK,	COLOR_RED);
    init_pair (COLOR_ID_WHITE,	COLOR_BLACK,	COLOR_WHITE);
    init_pair (COLOR_ID_AVAIL,	COLOR_YELLOW,	COLOR_BLACK);
    init_pair (COLOR_ID_WALL,	COLOR_BLUE,	COLOR_BLACK); 
  
    /* continual getch() */
    do {

      /* XXX: DIRTY */
      reversi_window_print_board (stdscr, &game);	/* render the map */
      reversi_window_print_panel (stdscr, &game);	/* render the panel */
      reversi_window_print_counter (stdscr, &game);	/* render the panel */

      if (!vCmp (winpos, V_QUEENSTEP [QS_LEFT_UP]))
	break;
  
      winpos = reversi_get_window_pos_by_cursor (game.cursor);
      move (winpos.i, winpos.j);
  
      winpos = reversi_window_handle_keypress (stdscr, &game, getch ());
  
      refresh ();

    } while (1);

    if (!reversi_window_game_over (stdscr, &game))
      break;
  }

  endwin ();
  return 0;
}
