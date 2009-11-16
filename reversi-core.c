/*-------------------------------------------------------*
 * reversi-core.c	( Reversi Game Ver 3 )		 *
 *-------------------------------------------------------*
 * target : Virtual Reversi Game Core	 		 *
 * create : 07/11/27					 *
 * update :   /  /					 *
 * author : Chitsaou Yorkxin (u96504@csie.ntnu.edu.tw)	 *
 *-------------------------------------------------------*/

#include "reversi.h"

void
reversi_initialize_game (game)
  REVERSI_GAME *game;
{
  USCHAR i, j;

  /* reset all cells */
  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++)
      game -> map [i][j] = S_NONE;

  /* put the initial cells */
  game -> map [3][3] = S_BLACK;
  game -> map [4][4] = S_BLACK;
  game -> map [3][4] = S_WHITE;
  game -> map [4][3] = S_WHITE;

  /* set the first player turn */
  game -> turn = S_BLACK;

  /* nobody wins */
  game -> winner = S_NONE;

  /* set the inital cursor position */
  game -> cursor.i = 3;
  game -> cursor.j = 4;

  reversi_counter (game);
  reversi_find_available (game);

  return ;
}

char
reversi_is_cursor_on_wall (cursor, queenstep)
  VECTOR cursor;
  int queenstep;
{
  switch (queenstep)
  {
    /* Up or Down */
    case QS_UP:
      return cursor.i == 0;

    case QS_DOWN:
      return cursor.i == 7;

    case QS_LEFT:
      return cursor.j == 0;

    case QS_RIGHT:
      return cursor.j == 7;

    case QS_LEFT_UP:
      return cursor.i == 0 || cursor.j == 0;

    case QS_RIGHT_UP:
      return cursor.i == 0 || cursor.j == 7;

    case QS_LEFT_DOWN:
      return cursor.i == 7 || cursor.j == 0;

    case QS_RIGHT_DOWN:
      return cursor.i == 7 || cursor.j == 7;
  }
}

int
reversi_available_to_put (game)
  REVERSI_GAME *game;
{
  return game -> map  [game -> cursor.i][game -> cursor.j] == S_AVAIL;
}

void
reversi_reverse_route (game, cstart, cend, vector)
  REVERSI_GAME *game;
  VECTOR cstart, cend, vector;
{
  do {
    game -> map [cstart.i][cstart.j] = game -> turn;
    cstart = vPlus (cstart, vector);
  } while (vCmp (cstart, cend));

  return ;
}

void
reversi_do_reverse (game)
  REVERSI_GAME *game;
{
  int qs;
  for (qs = QS_UP; qs <= QS_RIGHT_DOWN; qs++)
  {
    VECTOR cstart = vPlus (game -> cursor, V_QUEENSTEP [qs]);

    if (game -> map [cstart.i][cstart.j] == S_NONE ||
	game -> map [cstart.i][cstart.j] == game -> turn ||
	reversi_is_cursor_on_wall (game -> cursor, qs))
      continue;

    REVERSI_STAT opposite = reversi_get_opposite_turn (game -> turn);

    VECTOR cend = reversi_find_contiunity_vectorwise (
        game, cstart, qs, opposite);

    if (vCmp (cend, V_QUEENSTEP [QS_LEFT_UP]) && /* {-1, -1} */
        game -> map [cend.i][cend.j] == game -> turn)
    {
      reversi_reverse_route (game, cstart, cend, V_QUEENSTEP [qs]);
    }
  }
}


void
reversi_put (game)
  REVERSI_GAME *game;
{
  game -> map [game -> cursor.i][game -> cursor.j] = game -> turn;

  reversi_map_replace (game, S_AVAIL, S_NONE);

  reversi_do_reverse (game);

  reversi_counter (game);

  reversi_change_turn (game);

  return ;
}

void
reversi_counter (game)
  REVERSI_GAME *game;
{
  USCHAR i, j;

  game -> countblack = 0;
  game -> countwhite = 0;

  for (i = 0; i < 8; i++)
  {
    for (j = 0; j < 8; j++)
    {
      if (game -> map [i][j] == S_BLACK)
	game -> countblack++;

      if (game -> map [i][j] == S_WHITE)
	game -> countwhite++;
    }
  }

  return;
}

REVERSI_STAT
reversi_get_opposite_turn (turn)
  REVERSI_STAT turn;
{
  return turn == S_BLACK ? S_WHITE : S_BLACK;
}

void
reversi_map_replace (game, find, target)
  REVERSI_GAME *game;
  REVERSI_STAT find, target;
{
  USCHAR i, j;
  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++)
      if (game -> map [i][j] == find)
	game -> map [i][j] = target;

  return ;
}

char
reversi_find_existance (game, stat)
  REVERSI_GAME *game;
  REVERSI_STAT stat;
{
  USCHAR i, j;

  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++)
      if (game -> map [i][j] == stat)
	return 1;

  return 0;
}

void
reversi_change_turn (game)
  REVERSI_GAME *game;
{

  game -> turn = reversi_get_opposite_turn (game -> turn);
  reversi_find_available (game);

  game -> winner = reversi_whois_winner (game);
  if (game -> winner)
    return ;

  if (!reversi_find_existance (game, S_AVAIL))
  {
    game -> turn = reversi_get_opposite_turn (game -> turn);
    reversi_find_available (game);

    if (!reversi_find_existance (game, S_AVAIL))
      game -> winner = reversi_whois_winner (game);
  }

  return ;
}


REVERSI_STAT
reversi_whois_winner (game)
  REVERSI_GAME *game;
{
  if (!reversi_find_existance (game, S_AVAIL))
  {
    return (game -> countblack > game -> countwhite) ?
      S_BLACK : S_WHITE;
  }

  return S_NONE;
}

void
reversi_find_available (game)
  REVERSI_GAME *game;
{
  VECTOR curr;
  int qs;

  REVERSI_STAT opposite = reversi_get_opposite_turn (game -> turn);

  for (curr.i = 0; curr.i < 8; (curr.i)++)
  {
    for (curr.j = 0; curr.j < 8; (curr.j)++)
    {
      if (game -> map [curr.i][curr.j] == game -> turn)
      {
	for (qs = QS_UP; qs <= QS_RIGHT_DOWN; qs++)
	{
	  /* go one step */
	  VECTOR cstart = vPlus (curr, V_QUEENSTEP [qs]);
	  
	  /* checking: if
	   * 1) map @ start point is NONE or
	   * 2) map @ start point is mine or
	   * 3) the current point is on the wallside,
	   * then discard the process */
	  if (game -> map [cstart.i][cstart.j] == S_NONE ||
	      game -> map [cstart.i][cstart.j] == game -> turn ||
	      reversi_is_cursor_on_wall (curr, qs))
	    continue;

	  /* perform the process of finding contiunity;
	   * will get the next-step point 
	   * of the end point 
	   * of the contiunity;
	   * i.e. we got OOOOX
	   *                 ^ this */
	  VECTOR cend = reversi_find_contiunity_vectorwise (
	      game, cstart, qs, opposite);

	  /* checking: if
	   * 1) the end point is {-1, -1} (no valid point found) or
	   * 2) the end point is not empty,
	   * then discard the process */
	  if (vCmp (cend, V_QUEENSTEP [QS_LEFT_UP]) &&
	      game -> map [cend.i][cend.j] == S_NONE)
	  {
	    game -> map [cend.i][cend.j] = S_AVAIL;
	  }
	}
      }
    }
  }
}

/* Returns the terminal cursor of the contiunity */
/* ?OOOOO? */
/*  >----^ */

VECTOR
reversi_find_contiunity_vectorwise (game, curr, qs, target)
  REVERSI_GAME *game;
  REVERSI_STAT target;
  VECTOR curr;
  int qs;
{
  while (game -> map [curr.i][curr.j] == target)
  {
    if (reversi_is_cursor_on_wall (curr, qs))
      return V_QUEENSTEP [QS_LEFT_UP];

    curr = vPlus (curr, V_QUEENSTEP [qs]);
  }

  return curr;	/* found the terminator */
}

