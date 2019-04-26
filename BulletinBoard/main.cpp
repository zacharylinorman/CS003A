/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Bulletin Board
 * CLASS         : CS03A
 * SECTION       : MW: 1-2:25, TH: 1-3:05
 * DUE DATE      : 3/19/19
 ****************************************************************/
#include <iostream>
#include "bboard.h"

using namespace std;
/****************************************************************
 * Bulletin Board
 * ______________________________________________________________
 * This program simulates a bulletin board with a login system.
 * ______________________________________________________________
 * INPUT:
 *      login details and menu choices
 *
 * OUTPUT:
 *      the bulletin board
 *
 ****************************************************************/
int main(int argc,      // number of arguments
         char *argv[])  // the arguments
{
    // Create the bulliten board
    BBoard b("Bulletin Board");

    // Setup the users with the command line argument file name
    b.setup(argv[1]);

    // Attempt to login
    b.login();

    // Run the main loop
    b.run();
    return 0;
}
