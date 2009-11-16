/*-------------------------------------------------------*
 * vector.c		( Reversi Game Ver 3 )		 *
 *-------------------------------------------------------*
 * target : Vector Operations		 		 *
 * create : 07/11/27					 *
 * update :   /  /					 *
 * author : Chitsaou Yorkxin (u96504@csie.ntnu.edu.tw)	 *
 *-------------------------------------------------------*/

#include "reversi.h"

VECTOR
vPlus (a, b)
  VECTOR a, b;
{

  VECTOR c = {
    a.i + b.i,
    a.j + b.j
  };

  return c;
}

VECTOR
vMultiplyConst (a, b)
  VECTOR a;
  char b;
{
  VECTOR c = {
    a.i * b,
    a.j * b
  };

  return c;
}

VECTOR
vMinus (a, b)
  VECTOR a, b;
{
  return vPlus (a, vMultiplyConst (b, -1));
}

int
vCmp (a, b)
  VECTOR a, b;
{
  return !((a.i == b.i) && (a.j == b.j));
}
