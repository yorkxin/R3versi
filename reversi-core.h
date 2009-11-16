/*-------------------------------------------------------*
 * reversi-core.h	( Reversi Game Ver 3 )		 *
 *-------------------------------------------------------*
 * target : Virtual Reversi Game Core Definitions	 *
 * create : 07/11/27					 *
 * update :   /  /					 *
 * author : Chitsaou Yorkxin (u96504@csie.ntnu.edu.tw)	 *
 *-------------------------------------------------------*/

#ifndef __REVERSI_CORE_H
#define __REVERSI_CORE_H

typedef unsigned char USCHAR;
typedef unsigned int USINT;

typedef enum {
  S_NONE,
  S_BLACK,
  S_WHITE,
  S_AVAIL
} REVERSI_STAT;

typedef struct {
  REVERSI_STAT map [8][8];
  REVERSI_STAT turn, winner;
  VECTOR cursor;
  USINT countblack, countwhite;
} REVERSI_GAME;

#endif		/* __REVERSI_CORE_H */
