#include <iostream>
#include <cstdlib>
#include <string>
#include "header.h"
using namespace std;

//-------------------------------------------------------------------
//  drawCard()
//      Uses rand() to draw a card then returns the numerical
//	value and card name
//-------------------------------------------------------------------
int drawCard(string &card, int drawerPoints){
    // Random rank from 0-12
    int rank = rand() % 13;

    // Random suit from 0-3
    int suit = rand() % 4;

    // Return the name of the card using other functions
    card = getRank(rank) + " of " + getSuit(suit);

    // If the card is an ace
    if(rank == 0){

        // If the 11 will make the player bust, use the 1
        if(drawerPoints + 11 > 21){
            return 1;
        }else {
            // Otherwise use the 11
            return 11;
        }
    }else if(rank > 9){
        // Face cards count as 10
        return 10;
    }
    // Return the value of the card
    return rank + 1;
}

/********************************************************************
 * getSuit
 *  This function returns the name of the suit according to the given
 *  number
 ********************************************************************/
string getSuit(int num){
    switch(num){
    case 0:
        return "Spades";
    case 1:
        return "Clubs";
    case 2:
        return "Diamonds";
    case 3:
        return "Hearts";
    }
}

/********************************************************************
 * getRank
 *  This function returns the name of the rank according to the given
 *  number
 ********************************************************************/
string getRank(int num){
    // HYPERGRADE DOES NOT HAVE C++11 SUPPORT
    /*
    // Special cases
    if(num == 0){
        return "Ace";
    }else if(num == 10){
        return "Jack";
    }else if(num == 11){
        return "Queen";
    }else if(num == 12){
        return "King";
    }

    // If not a special case, return the value as a string
    return to_string(num + 1);
    */

    // So, use a switch statement instead
    switch(num){
    case 0:
        return "Ace";
    case 1:
        return "Two";
    case 2:
        return "Three";
    case 3:
        return "Four";
    case 4:
        return "Five";
    case 5:
        return "Six";
    case 6:
        return "Seven";
    case 7:
        return "Eight";
    case 8:
        return "Nine";
    case 9:
        return "Ten";
    case 10:
        return "Jack";
    case 11:
        return "Queen";
    case 12:
        return "King";
    }

}
