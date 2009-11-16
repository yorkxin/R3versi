/*-------------------------------------------------------*
 * visio.h		( Reversi Game Ver 3 )		 *
 *-------------------------------------------------------*
 * target : Terminal "Graphic" User Interface 		 *
 * create : 07/11/27					 *
 * update :   /  /					 *
 * author : Chitsaou Yorkxin (u96504@csie.ntnu.edu.tw)	 *
 *-------------------------------------------------------*
 * notice : pdcurses package for Dev-C++ is required!!	 *
 *-------------------------------------------------------*/

#ifndef __VISIO_H
#define __VISIO_H

#include <string.h>
#include <curses.h>

#define COLOR_ID_NONE	0
#define COLOR_ID_BLACK	1
#define COLOR_ID_WHITE	2
#define COLOR_ID_AVAIL	3
#define COLOR_ID_WALL	4

#define MAP_COLOR_NONE 	(COLOR_PAIR (COLOR_ID_NONE))
#define MAP_COLOR_BLACK	(COLOR_PAIR (COLOR_ID_BLACK))
#define MAP_COLOR_WHITE	(COLOR_PAIR (COLOR_ID_WHITE))
#define MAP_COLOR_AVAIL	(COLOR_PAIR (COLOR_ID_AVAIL))
#define MAP_COLOR_WALL	(COLOR_PAIR (COLOR_ID_WALL))

static int color_scheme [COLOR_ID_WALL + 1] = {
  MAP_COLOR_NONE,
  MAP_COLOR_BLACK,
  MAP_COLOR_WHITE,
  MAP_COLOR_AVAIL,
  MAP_COLOR_WALL
};

static char *cell_string [S_AVAIL + 2] = {
  "  ", "  ", "  ", " #", "| "
};

#define MAP_SEPARATOR	"+---+---+---+---+---+---+---+---+\n"

#endif		/* __VISIO_H */
