#ifndef HEADER_H
#define HEADER_H
#include <iostream>

using namespace std;

/********************************************************************
 * getRank
 *  This function returns the name of the rank according to the given
 *  number
 ********************************************************************/
string getRank(int num); // The rank number


/********************************************************************
 * getSuit
 *  This function returns the name of the suit according to the given
 *  number
 ********************************************************************/
string getSuit(int num); // The suit number


//-------------------------------------------------------------------
//  drawCard()
//      Uses rand() to draw a card then returns the numerical
//	value and card name
//-------------------------------------------------------------------
int drawCard(string &card,                 //IN - card name
              int drawer_points);          //IN - drawer's total points



#endif // HEADER_H
