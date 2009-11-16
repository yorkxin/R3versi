/*-------------------------------------------------------*
 * vector.h		( Reversi Game Ver 3 )		 *
 *-------------------------------------------------------*
 * target : Vector System Definitions	 		 *
 * create : 07/11/27					 *
 * update :   /  /					 *
 * author : Chitsaou Yorkxin (u96504@csie.ntnu.edu.tw)	 *
 *-------------------------------------------------------*/

#ifndef __VECTOR_H
#define __VECTOR_H

typedef struct {
  char i;
  char j;
} VECTOR;

/* the 8-direction Queen Step */
static VECTOR V_QUEENSTEP [9] = {
  {0, 0},	/* 原地 */
  {-1, 0},	/* 上 */
  {1, 0},	/* 下 */
  {0, -1},	/* 左 */
  {0, 1},	/* 右 */
  {-1, -1},	/* 左上 */
  {1, -1},	/* 左下 */
  {-1, 1},	/* 右上 */
  {1, 1}	/* 右下 */
};


#define QS_ORIGIN	0
#define QS_UP		1
#define QS_DOWN		2
#define QS_LEFT		3
#define QS_RIGHT	4
#define QS_LEFT_UP	5
#define QS_LEFT_DOWN	6
#define QS_RIGHT_UP	7
#define QS_RIGHT_DOWN	8

#endif
