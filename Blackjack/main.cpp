/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Blackjack
 * CLASS         : CS03A
 * SECTION       : MW: 1-2:25, TH: 1-3:05
 * DUE DATE      : 3/1/19
 ****************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "header.h"

using namespace std;

/****************************************************************
 * Blackjack
 * ______________________________________________________________
 * This program simulates the game of Blackjack with one player
 * versus the dealer.
 * ______________________________________________________________
 * INPUT:
 *      bet         : The amount for the player to bet
 *      yesNo       : Yes or Now
 *
 * OUTPUT:
 *      The game of blackjack.
 *
 ****************************************************************/
int main()
{
    // VARIABLES
    int playerTotal;        // The player's total card value
    int dealerTotal;        // The dealer's total card value
    int playerMoney = 100;  // The player's money

    string card;            // The card drawn

    int bet;                // The amount the player is betting
    bool endTurn;           // Whether to end the turn or not
    char yesNo;             // Yes or No

    //srand(time(0));         // Random cards each time
    srand(333);

    do{
        // INITIALIZE VARIABLES
        playerTotal = 0;
        dealerTotal = 0;
        endTurn = false;

        // Receive bet amount
        cout << "You have $" << playerMoney << ". Enter bet: ";
        cin >> bet;
        cout << endl;

        // Draw player starting cards
        cout << "Your cards are: " << endl;
        playerTotal += drawCard(card, playerTotal);
        cout << "  " << card << endl;
        playerTotal += drawCard(card, playerTotal);
        cout << "  " << card << endl;

        // Player's turn- allow them to draw until they go over 21
        while(playerTotal < 21){
            do{
                // Ask if they want to draw a card
                cout << "Your total is " << playerTotal << ". Do you want "
                     << "another card (y/n)? ";
                cin >> yesNo;
                cout << endl;

                // If they do, draw one
                if(yesNo == 'y'){
                    playerTotal += drawCard(card, playerTotal);
                    cout << "You draw a: " << endl;
                    cout << "  " << card << endl;
                } else if(yesNo == 'n'){
                    // Otherwise break out of the loop
                    endTurn = true;
                }
            }while(!(yesNo == 'y' || yesNo == 'n'));

            if(endTurn){
                break;
            }
        }

        // If the player went over 21, they busted
        if(playerTotal > 21){
            cout << "Your total is " << playerTotal << ". You busted!"
                 << endl;
            playerMoney -= bet;
        } else{ // Otherwise, dealer's turn

            // Dealer's starting cards
            cout << endl << endl;
            cout << "The dealer's cards are: " << endl;
            dealerTotal += drawCard(card, dealerTotal);
            cout << "  " << card << endl;
            dealerTotal += drawCard(card, dealerTotal);
            cout << "  " << card << endl;

            cout << "The dealer's total is " << dealerTotal
                 << "." << endl;

            // The dealer continues to draw if <= 16
            while(dealerTotal <= 16){
                cout << "The dealer draws a card." << endl;
                dealerTotal += drawCard(card, dealerTotal);
                cout << "  " << card << endl;
                cout << "The dealer's total is " << dealerTotal
                     << "." << endl;
            }

            // Process the end of game
            if(dealerTotal > 21){
                // Dealer bust

                cout << "The dealer busted!" << endl;
                cout << "You win $" << bet << "." << endl;
                playerMoney += bet;
            }else if(dealerTotal > playerTotal){
                // Dealer wins

                cout << "Too bad.  You lose $" << bet << "." <<endl;
                playerMoney -= bet;
            }else if(dealerTotal == playerTotal){
                // Tie

                cout << "A draw! You get back your $" << bet
                     << "." << endl;
            }else {
                // Player wins

                cout << "You win $" << bet << "." << endl;
                playerMoney += bet;
            }
        }

        cout << endl;

        if(playerMoney > 0 && playerMoney < 1000){
            // Ask if player wants to play again
            do{
                cout << "Play again? (y/n): ";
                cin >> yesNo;
                cout << endl;
            }while(!(yesNo == 'y' || yesNo == 'n'));
        }else{
            // If player's money is 0 or less, or 1000 or more, game over

            cout << "You have $" << playerMoney << ". GAME OVER." << endl;
        }


    }while(playerMoney > 0 && playerMoney < 1000 && yesNo == 'y');

    return 0;
}
