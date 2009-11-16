/*-------------------------------------------------------*
 * visio.c		( Reversi Game Ver 3 )		 *
 *-------------------------------------------------------*
 * target : Terminal "Graphic" User Interface 		 *
 * create : 07/11/27					 *
 * update :   /  /					 *
 * author : Chitsaou Yorkxin (u96504@csie.ntnu.edu.tw)	 *
 *-------------------------------------------------------*/

#include "reversi.h"

void
wprintw_attr (win, attr, string)
  WINDOW *win;
  int attr;
  char *string;
{
  attron (attr);
  wprintw (win, string);
  attroff (attr);

  return ;
}

void
reversi_window_print_panel (win, game)
  WINDOW *win;
  REVERSI_GAME *game;
{

  wmove (win, 1, 38);
  wprintw (win, "by Chitsaou Yorkxin @CSIE, NTNU");

  wmove (win, 3, 38);
  reversi_window_print_stat (win, game -> turn);
  wprintw (win, "'s turn");

  wmove (win, 15, 38);

  /*
  char buf [10]= "";
  sprintf (buf, "%d, %d", 
      game -> cursor.i,
      game -> cursor.j);

  wprintw (win, "%s", buf);

  */
  wprintw (win, "%d, %d",
      game -> cursor.i,
      game -> cursor.j);

  return ;
}

void
reversi_window_print_counter (win, game)
  WINDOW *win;
  REVERSI_GAME *game;
{
  /*
  char buf[10] = "";
  */
  int i, j;

  int counter_begin_line = 19;
  int counter_lines = 4;

  for (i = 0; i < counter_lines; i++)
  {
    wmove (win, counter_begin_line + i, 0);

    /*
    sprintf (buf, "%*s", 80, " ");
    wprintw (win, "%s", buf);
    */

    wprintw (win, "%*s", 80, " ");
  }

  wmove (win, counter_begin_line - 1, 36 - 2);

  /*
  sprintf (buf, "%2d    %2d",
      game -> countblack,
      game -> countwhite);
  wprintw (win, "%s", buf);

  */

  wprintw (win, "%2d    %2d",
      game -> countblack,
      game -> countwhite);

  /* print counter bar for black */
  for (i = 1, j = 36; i <= (game -> countblack); i++, j-=2)
  {
    if (i % 16 == 1)
      j = 36;

    wmove (win, counter_begin_line + ((i - 1) / 16) , j);
    reversi_window_print_stat (win, S_BLACK);

  }
  
  /* print counter bar for white */
  for (i = 1, j = 38; i <= (game -> countwhite); i++, j+=2)
  {
    if (i % 16 == 1)
      j = 38;

    wmove (win, counter_begin_line + ((i - 1) / 16) , j);
    reversi_window_print_stat (win, S_WHITE);

  }
  
  return ;
}


void
reversi_window_print_stat (win, stat)
  WINDOW *win;
  REVERSI_STAT stat;
{
  wprintw_attr (win, color_scheme [stat], cell_string [stat]);

  return ;
}

void
reversi_window_print_board (win, game)
  REVERSI_GAME *game;
  WINDOW *win;
{
  wmove (win, 0, 0); 

  USCHAR i, j;

  for (i = 0; i < 8; i++)
  {
    wprintw_attr (win, color_scheme [COLOR_ID_WALL],  MAP_SEPARATOR);
    for (j = 0; j < 8; j++)
    {
      wprintw_attr (win, color_scheme [COLOR_ID_WALL],
	  cell_string [COLOR_ID_WALL]);

      reversi_window_print_stat (win, game -> map [i][j]);
    }
    wprintw_attr (win, color_scheme [COLOR_ID_WALL],
	cell_string [COLOR_ID_WALL]);

    wprintw (win, "\n");
  }
  wprintw_attr (win, color_scheme [COLOR_ID_WALL],  MAP_SEPARATOR);
}

VECTOR
reversi_get_window_pos_by_cursor (cursor)
  VECTOR cursor;
{
  VECTOR pos;

  pos.i = cursor.i * 2 + 1;
  pos.j = cursor.j * 4 + 1;

  return pos;
}


VECTOR
reversi_window_handle_keypress (win, game, ch)
  WINDOW *win;
  REVERSI_GAME *game;
  int ch;
{
  switch (ch)
  {
    case 'p':
    case ' ':
    case KEY_ENTER:
      if (reversi_available_to_put (game))
	reversi_put (game);

      if (game -> winner)
	return V_QUEENSTEP [QS_LEFT_UP];

      break;

    /* the arrow keys */
#if 0
    case 'h':
    case 'j':
    case 'k':
    case 'l':
    case KEY_LEFT:
    case KEY_DOWN:
    case KEY_UP:
    case KEY_RIGHT:
#endif
    default:
      switch (ch)
      {

        case 'h':
        case KEY_LEFT:
          if (!reversi_is_cursor_on_wall (game->cursor, QS_LEFT))
	    game -> cursor = vPlus (V_QUEENSTEP [QS_LEFT], game -> cursor);

          break;
    
        case 'j':
        case KEY_DOWN:
          if (!reversi_is_cursor_on_wall (game->cursor, QS_DOWN))
	    game -> cursor = vPlus (V_QUEENSTEP [QS_DOWN], game -> cursor);
    
          break;
    
        case 'k':
        case KEY_UP:
          if (!reversi_is_cursor_on_wall (game->cursor, QS_UP))
	    game -> cursor = vPlus (V_QUEENSTEP [QS_UP], game -> cursor);
    
          break;
    
        case 'l':
        case KEY_RIGHT:
          if (!reversi_is_cursor_on_wall (game->cursor, QS_RIGHT))
    	    game -> cursor = vPlus (V_QUEENSTEP [QS_RIGHT], game -> cursor);
    
          break;

      }
      break;
  }
  return reversi_get_window_pos_by_cursor (game -> cursor);
}

char
reversi_window_game_over (win, game)
  WINDOW *win;
  REVERSI_GAME *game;
{
  wmove (win, 7, 38);
  wprintw (win, "THE WINNER IS ...");

  int i = 7;
  while (i--)
    reversi_window_print_stat (win, game -> turn);

  wmove (win, 9, 38);
  wprintw (win, "Wanna play again ? [y/n]");

  char ans;
  while (ans = getch ())
  {
    if (ans == 'y')
      return 1;
    else if (ans == 'n')
      return 0;
  }
}
